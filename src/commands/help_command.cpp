// By: Landon Prince (5/10/2024)

#include "core/utils.h"
#include "commands/help_command.h"
#include <iostream>

bool HelpCommand::execute() {
    if (commandName.empty()) {
        Utils::addSeparator();
        std::cout << "Available commands [" << ct->getCommands().size() << "]:\n" << std::endl;
        ct->printCommands();
        Utils::addSeparator();
        std::cout << "Enter 'help [command]' for information on a specific command" << std::endl;
        Utils::addSeparator();
    } else {
        auto helpFunc = ct->findHelp(commandName);
        if (helpFunc) helpFunc();
        else throw std::logic_error("unknown command: " + commandName);
    }
    return true;
}

void HelpCommand::help() {
    Utils::addSeparator();
    std::cout << "help - List all available commands\n";
    std::cout << "help [command] - Display help for a given command\n";
    std::cout << "Example: help faces\n";
    Utils::addSeparator();
}

HelpCommand::HelpCommand(ImageManager* im, CommandTrie* ct, const std::deque<std::string>& params)
: CommandImpl(im), ct(ct), commandName() {
    if (params.size() > 1)
        throw std::length_error("invalid number of parameters (0 or 1)");
    if (!params.empty())
        commandName = Utils::strLower(params.front());
}


