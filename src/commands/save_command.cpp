// By: Landon Prince (5/13/2024)

#include "core/image_manager.h"
#include "commands/save_command.h"
#include <iostream>

bool SaveCommand::execute() {
    im->saveImage();
    return true;
}

void SaveCommand::help() {
    std::cout << "save - saves the loaded image to a new file\n";
}

SaveCommand::SaveCommand(ImageManager *im) : CommandImpl(im) {}
