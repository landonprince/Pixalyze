// By: Landon Prince (5/12/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/gray_command.h"
#include <iostream>

bool GrayCommand::execute() {
    im->toGray();
    return true;
}

void GrayCommand::help() {
    Utils::addSeparator();
    std::cout << "gray - Convert loaded image from color to grayscale\n";
    Utils::addSeparator();
}

GrayCommand::GrayCommand(ImageManager *im) : CommandImpl(im) {}

