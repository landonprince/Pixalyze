// By: Landon Prince (5/13/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/edges_command.h"
#include <iostream>

bool EdgesCommand::execute() {
    im->findEdges();
    return true;
}

void EdgesCommand::help() {
    Utils::addSeparator();
    std::cout << "edges - applies edge detection to loaded image\n";
    Utils::addSeparator();
}

EdgesCommand::EdgesCommand(ImageManager *im) : CommandImpl(im) {}