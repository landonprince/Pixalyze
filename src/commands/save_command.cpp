// By: Landon Prince (5/13/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/save_command.h"
#include <iostream>

bool SaveCommand::execute() {
    im->saveImage();
    return true;
}

void SaveCommand::help() {
    Utils::addSeparator();
    std::cout << "save - saves loaded image to a new file\n";
    Utils::addSeparator();
}

SaveCommand::SaveCommand(ImageManager *im) : CommandImpl(im) {}
