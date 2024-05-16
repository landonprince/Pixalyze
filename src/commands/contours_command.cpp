// By: Landon Prince (5/15/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/contours_command.h"
#include <iostream>

bool ContoursCommand::execute() {
    im->findContours();
    return true;
}

void ContoursCommand::help() {
    Utils::addSeparator();
    std::cout << "contours - applies contour detection on loaded image\n";
    Utils::addSeparator();
}

ContoursCommand::ContoursCommand(ImageManager *im) : CommandImpl(im) {}
