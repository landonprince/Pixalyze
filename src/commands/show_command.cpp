// By: Landon Prince (5/11/2024)

#include "core/image_manager.h"
#include "commands/show_command.h"
#include <iostream>

bool ShowCommand::execute() {
    im->showImage();
    return true;
}

void ShowCommand::help() {
    std::cout << "show - displays the currently loaded image\n";
}

ShowCommand::ShowCommand(ImageManager *im) : CommandImpl(im) {}
