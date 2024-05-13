// By: Landon Prince (5/10/2024)

#include "core/utils.h"
#include "core/command_factory.h"
#include "commands/quit_command.h"
#include "commands/help_command.h"
#include "commands/load_command.h"
#include "commands/show_command.h"
#include "commands/analyze_command.h"
#include "commands/grayscale_command.h"
#include "commands/color_command.h"

CommandFactory::CommandFactory(ImageManager* im, CommandTrie* ct)
        : im(im), ct(ct) { registerCommands(); }

size_t split(const std::string& txt, std::deque<std::string>& strs, char ch) {
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    while (pos != std::string::npos) {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;
        pos = txt.find(ch, initialPos);
    }
    strs.push_back(txt.substr(initialPos,
                              std::min(pos, txt.size()) - initialPos + 1));
    return strs.size();
}

void CommandFactory::registerCommands() {
    ct->registerCommand("quit", &QuitCommand::help,
                        [this]() { return this->makeQuit(); });
    ct->registerCommand("help", &HelpCommand::help,
                        [this]() { return this->makeHelp(); });
    ct->registerCommand("load", &LoadCommand::help,
                        [this]() { return this->makeLoad(); });
    ct->registerCommand("show", &ShowCommand::help,
                        [this]() { return this->makeShow(); });
    ct->registerCommand("analyze", &AnalyzeCommand::help,
                        [this]() { return this->makeAnalyze(); });
    ct->registerCommand("grayscale", &GrayscaleCommand::help,
                        [this]() { return this->makeGrayscale(); });
    ct->registerCommand("color", &ColorCommand::help,
                        [this]() { return this->makeColor(); });
}

Command CommandFactory::makeCommand(const std::string& input) {
    // separate the command from the input parameters
    split(input, params, ' ');
    std::string keyword = strLower(params.front());
    params.pop_front();

    // use command trie to determine which command to create
    auto factoryFunc = ct->findFactory(keyword);
    if (factoryFunc) return factoryFunc();
    else if (keyword.empty()) throw std::logic_error("use quit command to exit...");
    else throw std::logic_error("unrecognized command: " + keyword);
}

Command CommandFactory::makeQuit() {
    return Command(new QuitCommand(im));
}

Command CommandFactory::makeHelp() {
    return Command(new HelpCommand(im, ct, params));
}

Command CommandFactory::makeLoad() {
    return Command(new LoadCommand(im, params));
}

Command CommandFactory::makeShow() {
    return Command(new ShowCommand(im));
}

Command CommandFactory::makeAnalyze() {
    return Command(new AnalyzeCommand(im));
}

Command CommandFactory::makeGrayscale() {
    return Command(new GrayscaleCommand(im));
}

Command CommandFactory::makeColor() {
    return Command(new ColorCommand(im));
}