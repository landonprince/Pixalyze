// By: Landon Prince (5/12/2024)

#include "core/utils.h"
#include "core/image_manager.h"
#include "commands/analyze_command.h"
#include <iostream>

bool AnalyzeCommand::execute() {
    im->printInfo();
    return true;
}

void AnalyzeCommand::help() {
    Utils::addSeparator();
    std::cout << "analyze - Display properties of the loaded image\n";
    Utils::addSeparator();
}

AnalyzeCommand::AnalyzeCommand(ImageManager* im) : CommandImpl(im) {}

