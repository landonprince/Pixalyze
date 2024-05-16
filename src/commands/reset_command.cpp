// By: Landon Prince (5/15/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/reset_command.h"
#include <iostream>

bool ResetCommand::execute() {
    im->resetImage();
    return true;
}

void ResetCommand::help() {
    Utils::addSeparator();
    std::cout << "reset - reset modifications made to loaded image\n";
    Utils::addSeparator();
}

ResetCommand::ResetCommand(ImageManager *im) : CommandImpl(im) {}
