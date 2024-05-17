// By: Landon Prince (5/10/2024)

#include "core/utils.h"
#include "core/command_factory.h"
#include "commands/quit_command.h"
#include "commands/help_command.h"
#include "commands/load_command.h"
#include "commands/show_command.h"
#include "commands/analyze_command.h"
#include "commands/gray_command.h"
#include "commands/color_command.h"
#include "commands/save_command.h"
#include "commands/edges_command.h"
#include "commands/ascii_command.h"
#include "commands/blur_command.h"
#include "commands/smooth_command.h"
#include "commands/text_command.h"
#include "commands/contours_command.h"
#include "commands/reset_command.h"
#include "commands/histogram_command.h"
#include "commands/faces_command.h"

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

Command CommandFactory::makeCommand(const std::string& input) {
    split(input, params, ' ');
    std::string keyword = Utils::strLower(params.front());
    params.pop_front();

    auto factoryFunc = ct->findFactory(keyword);
    if (factoryFunc) return factoryFunc();
    else if (keyword.empty()) throw std::logic_error("use quit command to exit...");
    else throw std::logic_error("unrecognized command: " + keyword);
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
    ct->registerCommand("gray", &GrayCommand::help,
                        [this]() { return this->makeGray(); });
    ct->registerCommand("color", &ColorCommand::help,
                        [this]() { return this->makeColor(); });
    ct->registerCommand("save", &SaveCommand::help,
                        [this]() { return this->makeSave(); });
    ct->registerCommand("edges", &EdgesCommand::help,
                        [this]() { return this->makeEdges(); });
    ct->registerCommand("ascii", &AsciiCommand::help,
                        [this]() { return this->makeAscii(); });
    ct->registerCommand("blur", &BlurCommand::help,
                        [this]() { return this->makeBlur(); });
    ct->registerCommand("smooth", &SmoothCommand::help,
                        [this]() { return this->makeSmooth(); });
    ct->registerCommand("text", &TextCommand::help,
                        [this]() { return this->makeText(); });
    ct->registerCommand("contours", &ContoursCommand::help,
                        [this]() { return this->makeContours(); });
    ct->registerCommand("reset", &ResetCommand::help,
                        [this]() { return this->makeReset(); });
    ct->registerCommand("histogram", &HistogramCommand::help,
                        [this]() { return this->makeHistogram(); });
    ct->registerCommand("faces", &FacesCommand::help,
                        [this]() { return this->makeFaces(); });
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

Command CommandFactory::makeGray() {
    return Command(new GrayCommand(im));
}

Command CommandFactory::makeColor() {
    return Command(new ColorCommand(im));
}

Command CommandFactory::makeSave() {
    return Command(new SaveCommand(im));
}

Command CommandFactory::makeEdges() {
    return Command(new EdgesCommand(im));
}

Command CommandFactory::makeAscii() {
    return Command(new AsciiCommand(im));
}

Command CommandFactory::makeBlur() {
    return Command(new BlurCommand(im));
}

Command CommandFactory::makeSmooth() {
    return Command(new SmoothCommand(im, params));
}

Command CommandFactory::makeText() {
    return Command(new TextCommand(im, params));
}

Command CommandFactory::makeContours() {
    return Command(new ContoursCommand(im));
}

Command CommandFactory::makeReset() {
    return Command(new ResetCommand(im));
}

Command CommandFactory::makeHistogram() {
    return Command(new HistogramCommand(im));
}

Command CommandFactory::makeFaces() {
    return Command(new FacesCommand(im));
}