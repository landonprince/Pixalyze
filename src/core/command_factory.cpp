// By: Landon Prince (5/10/2024)

#include "core/command_factory.h"
#include "core/utils.h"
#include "commands/command.h"
#include "commands/quit_command.h"
#include "commands/help_command.h"
#include "commands/load_command.h"

CommandFactory::CommandFactory(ImageManager* im)
        : im(im) {
    if (im == nullptr)
        throw std::runtime_error("ImageManager must be non-null");
}

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
    // separate the command from the input parameters
    std::deque<std::string> params;
    split(input, params, ' ');
    std::string keyword = strLower(params.front());
    params.pop_front();

    // determine which command to create
    if (keyword == "quit")
        return makeQuit();
    else if (keyword == "help")
        return makeHelp(params);
    else if (keyword == "load")
        return makeLoad(params);

    if (keyword.empty())
        throw std::logic_error("use quit command to exit...");
    else
        throw std::logic_error("unrecognized command: " + keyword);
}

Command CommandFactory::makeQuit() {
    return Command(new QuitCommand(im));
}

Command CommandFactory::makeHelp(const std::deque<std::string>& params) {
    return Command(new HelpCommand(im, params));
}

Command CommandFactory::makeLoad(const std::deque<std::string>& params) {
    return Command(new LoadCommand(im, params));
}



