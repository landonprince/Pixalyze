// By: Landon Prince (5/12/2024)

#include "core/image_manager.h"
#include "commands/analyze_command.h"
#include <iostream>

bool AnalyzeCommand::execute() {
    im->printInfo();
    return true;
}

void AnalyzeCommand::help() {
    std::cout << "analyze - prints properties of the loaded image\n";
}

AnalyzeCommand::AnalyzeCommand(ImageManager* im) : CommandImpl(im) {}

