// By: Landon Prince (5/12/2024)

#include "core/image_manager.h"
#include "commands/grayscale_command.h"
#include <iostream>

bool GrayscaleCommand::execute() {
    im->toGray();
    return true;
}

void GrayscaleCommand::help() {
    std::cout << "grayscale - converts loaded image from color to grayscale\n";
}

GrayscaleCommand::GrayscaleCommand(ImageManager *im) : CommandImpl(im) {}

