// By: Landon Prince (5/12/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/color_command.h"
#include <iostream>

bool ColorCommand::execute() {
    im->toColor();
    return true;
}

void ColorCommand::help() {
    Utils::addSeparator();
    std::cout << "color - Convert loaded image from grayscale to color\n";
    Utils::addSeparator();
}

ColorCommand::ColorCommand(ImageManager *im) : CommandImpl(im) {}