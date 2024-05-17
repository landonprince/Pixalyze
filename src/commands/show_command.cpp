// By: Landon Prince (5/11/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/show_command.h"
#include <iostream>

bool ShowCommand::execute() {
    im->showImage();
    return true;
}

void ShowCommand::help() {
    Utils::addSeparator();
    std::cout << "show - display loaded image in a new window\n";
    Utils::addSeparator();
}

ShowCommand::ShowCommand(ImageManager *im) : CommandImpl(im) {}
