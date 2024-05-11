// By: Landon Prince (5/10/2024)

#include "core/utils.h"
#include "commands/help_command.h"
#include "commands/quit_command.h"
#include "commands/load_command.h"
#include <iostream>

bool HelpCommand::execute()
{
    if (commandName.empty()) {
        std::cout << "Available commands:\n";
        std::cout << "  load\n";
        std::cout << "  help\n";
        std::cout << "  quit\n";
    } else {
        if (commandName == "quit")
            QuitCommand::help();
        else if (commandName == "help")
            HelpCommand::help();
        else if (commandName == "load")
            LoadCommand::help();
        else
            throw std::logic_error("unknown command: " + commandName);
    }
    return true;
}

void HelpCommand::help()
{
    std::cout << "help - list all commands\n";
    std::cout << "help [command] - display help for a given command\n";
}

HelpCommand::HelpCommand(ImageManager* im, const std::deque<std::string>& params)
        : CommandImpl(im), commandName() {
    if (params.size() > 1)
        throw std::length_error("invalid number of parameters (0 or 1)");
    if (!params.empty())
        commandName = strLower(params.front());
}
