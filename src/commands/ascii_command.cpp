// By: Landon Prince (5/13/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/ascii_command.h"
#include <iostream>

bool AsciiCommand::execute() {
    im->saveASCII();
    return true;
}

void AsciiCommand::help() {
    Utils::addSeparator();
    std::cout << "ascii - saves ascii art of loaded image to a new file\n";
    Utils::addSeparator();
}

AsciiCommand::AsciiCommand(ImageManager *im) : CommandImpl(im) {}
