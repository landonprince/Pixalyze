// By: Landon Prince (5/11/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/load_command.h"
#include <iostream>

bool LoadCommand::execute() {
    im->loadImage(imagePath);
    return true;
}

void LoadCommand::help() {
    Utils::addSeparator();
    std::cout << "load [image file path] - Load image from file path\n";
    std::cout << "Example: load C:\\pictures\\image.jpg\n";
    Utils::addSeparator();
}

LoadCommand::LoadCommand(ImageManager* im, const std::deque<std::string>& params)
        : CommandImpl(im), imagePath() {
    if (params.size() != 1)
        throw std::length_error("invalid number of parameters (1)");
    imagePath = params.front();
    if (!std::filesystem::exists(imagePath)) {
        throw std::invalid_argument("image file not found");
    }
    if (!Utils::isSupported(imagePath)) {
        throw std::invalid_argument("image type not supported");
    }
}