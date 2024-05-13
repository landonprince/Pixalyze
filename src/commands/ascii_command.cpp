// By: Landon Prince (5/13/2024)

#include "core/image_manager.h"
#include "commands/ascii_command.h"
#include <iostream>

bool AsciiCommand::execute() {
    im->saveASCII();
    return true;
}

void AsciiCommand::help() {
    std::cout << "ascii - saves ascii art of the loaded image to a new file\n";
}

AsciiCommand::AsciiCommand(ImageManager *im) : CommandImpl(im) {}
