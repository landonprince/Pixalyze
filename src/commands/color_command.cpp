// By: Landon Prince (5/12/2024)

#include "core/image_manager.h"
#include "commands/color_command.h"
#include <iostream>

bool ColorCommand::execute() {
    im->toColor();
    return true;
}

void ColorCommand::help() {
    std::cout << "color - converts loaded image from grayscale to color\n";
}

ColorCommand::ColorCommand(ImageManager *im) : CommandImpl(im) {}