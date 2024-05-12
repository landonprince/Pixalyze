// By: Landon Prince (5/10/2024)

#include "core/utils.h"
#include "commands/help_command.h"
#include <iostream>

bool HelpCommand::execute()
{
    if (commandName.empty()) {
        std::cout << "Available commands:\n";
        for (const auto& command : ct->getCommands()) {
            std::cout << command << std::endl;
        }
    } else {
        auto helpFunc = ct->findHelp(commandName);
        if (helpFunc) helpFunc();
        else throw std::logic_error("unknown command: " + commandName);
    }
    return true;
}

void HelpCommand::help()
{
    std::cout << "help - list all commands\n";
    std::cout << "help [command] - display help for a given command\n";
}

HelpCommand::HelpCommand(ImageManager* im, CommandTrie* ct, const std::deque<std::string>& params)
: CommandImpl(im), ct(ct), commandName() {
    if (params.size() > 1)
        throw std::length_error("invalid number of parameters (0 or 1)");
    if (!params.empty())
        commandName = strLower(params.front());
}


