// By: Landon Prince (5/10/2024)

#include "core/utils.h"
#include "commands/quit_command.h"
#include <iostream>

bool QuitCommand::execute() {
    Utils::addSeparator();
    std::cout << "Shutting down application...\n";
    Utils::addSeparator();
    return false;
}

void QuitCommand::help() {
    Utils::addSeparator();
    std::cout << "quit - Exit the application\n";
    Utils::addSeparator();
}

QuitCommand::QuitCommand(ImageManager *im) : CommandImpl(im) {}
