// By: Landon Prince (5/13/2024)

#include "core/image_manager.h"
#include "commands/edges_command.h"
#include <iostream>

bool EdgesCommand::execute() {
    im->findEdges();
    return true;
}

void EdgesCommand::help() {
    std::cout << "edges - detects all edges in loaded image\n";
}

EdgesCommand::EdgesCommand(ImageManager *im) : CommandImpl(im) {}