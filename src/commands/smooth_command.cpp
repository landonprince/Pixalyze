// By: Landon Prince (5/13/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/smooth_command.h"
#include <iostream>

bool SmoothCommand::execute() {
    im->smoothImage(intensity);
    return true;
}

void SmoothCommand::help() {
    Utils::addSeparator();
    std::cout << "smooth - smooth image with default intensity 1\n";
    std::cout << "smooth [intensity] - use custom smoothing intensity (1-3)\n";
    Utils::addSeparator();
}

SmoothCommand::SmoothCommand(ImageManager* im, const std::deque<std::string>& params)
        : CommandImpl(im), intensity(0) {
    if (!params.empty()) {
        if (params.size() > 1)
            throw std::length_error("invalid number of parameters (0 or 1)");
        try {
            intensity = std::stoi(params.front());
        } catch (const std::invalid_argument& ex) {
            throw std::invalid_argument("smoothness intensity not found");
        }
        if (intensity < 1 || intensity > 3) {
            throw std::invalid_argument("smoothness intensity not found");
        }
    }
    else {
        intensity = 1;
    }
}
