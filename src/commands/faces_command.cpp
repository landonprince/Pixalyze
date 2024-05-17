// By: Landon Prince (5/15/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/faces_command.h"
#include <iostream>

bool FacesCommand::execute() {
    im->detectFaces();
    return true;
}

void FacesCommand::help() {
    Utils::addSeparator();
    std::cout << "faces - Detect all faces in loaded image\n";
    Utils::addSeparator();
}

FacesCommand::FacesCommand(ImageManager *im) : CommandImpl(im) {}
