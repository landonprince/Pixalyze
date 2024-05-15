// By: Landon Prince (5/12/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/grayscale_command.h"
#include <iostream>

bool GrayscaleCommand::execute() {
    im->toGray();
    return true;
}

void GrayscaleCommand::help() {
    Utils::addSeparator();
    std::cout << "grayscale - converts loaded image from color to grayscale\n";
    Utils::addSeparator();
}

GrayscaleCommand::GrayscaleCommand(ImageManager *im) : CommandImpl(im) {}

