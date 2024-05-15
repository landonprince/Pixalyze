// By: Landon Prince (5/14/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/text_command.h"
#include <iostream>

bool TextCommand::execute() {
    im->addText(text, color, fontSize);
    return true;
}

void TextCommand::help() {
    Utils::addSeparator();
    std::cout << "smooth - smooth image with default intensity 1\n";
    std::cout << "smooth [intensity] - use custom smooth intensity (1-3)\n";
    Utils::addSeparator();
}

TextCommand::TextCommand(ImageManager* im, const std::deque<std::string>& params)
        : CommandImpl(im), text(), color(), fontSize(0) {
    if (params.empty() || params.size() > 3) {
        throw std::length_error("invalid number of parameters (1, 2, or 3)");
    }

    if (!params[0].empty()) {
        text = params[0];
    } else {
        throw std::invalid_argument("no text provided");
    }

    if (params.size() > 1) {
        if (!params[1].empty()) {
            try {
                fontSize = std::stod(params[1]);
            } catch (const std::invalid_argument& ex) {
                throw std::invalid_argument("invalid font size provided");
            }
        } else {
            fontSize = 20.0;
        }
    } else {
        fontSize = 20.0;
    }

    if (params.size() > 2) {
        if (!params[2].empty()) {
            if (Utils::getColorMap().find(
                    Utils::strLower(params[2])) != Utils::getColorMap().end()) {
                color = params[2];
            } else {
                throw std::invalid_argument("invalid color provided");
            }
        } else {
            color = "green";
        }
    } else {
        color = "green";
    }
}
