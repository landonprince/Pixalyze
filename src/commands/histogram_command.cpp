// By: Landon Prince (5/15/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/histogram_command.h"
#include <iostream>

bool HistogramCommand::execute() {
    im->createHistogram();
    return true;
}

void HistogramCommand::help() {
    Utils::addSeparator();
    std::cout << "histogram - create histogram of loaded image based on pixel value\n";
    Utils::addSeparator();
}

HistogramCommand::HistogramCommand(ImageManager *im) : CommandImpl(im) {}
