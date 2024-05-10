// By: Landon Prince (5/10/2024)

#include "commands/quit_command.h"
#include <iostream>

bool QuitCommand::execute() {
    return false;
}

void QuitCommand::help() {
    std::cout << "quit - exit the application\n";
}

QuitCommand::QuitCommand(ImageManager *im) : CommandImpl(im){}
