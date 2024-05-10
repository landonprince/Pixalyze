// By: Landon Prince (5/10/2024)

#include "core/command_factory.h"
#include "core/utils.h"
#include "commands/command.h"
#include "commands/quit_command.h"

CommandFactory::CommandFactory(ImageManager* im)
        : im(im) {
    if (im == nullptr)
        throw std::runtime_error("ImageManager must be non-null");
}

size_t split(const std::string& txt, std::deque<std::string>& strs, char ch) {
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    // decompose statement
    while (pos != std::string::npos) {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;
        pos = txt.find(ch, initialPos);
    }
    // add the last one
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

    // figure out which command to make
    if (keyword == "quit")
        return makeQuit();
    if (keyword.empty())
        throw std::logic_error("Use quit command to exit...");
    else
        throw std::logic_error("Unrecognized command: " + keyword);
}


Command CommandFactory::makeQuit()
{
    return Command(new QuitCommand(im));
}




