// By: Landon Prince (5/13/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/blur_command.h"
#include <iostream>

bool BlurCommand::execute() {
    im->blurImage();
    return true;
}

void BlurCommand::help() {
    Utils::addSeparator();
    std::cout << "blur - blurs the loaded image\n";
    Utils::addSeparator();
}

BlurCommand::BlurCommand(ImageManager *im) : CommandImpl(im) {}
