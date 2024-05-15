// By: Landon Prince (5/10/2024)

#include "core/image_manager.h"
#include "core/command_factory.h"
#include "core/utils.h"
#include <opencv2/core/utils/logger.hpp>
#include <iostream>
#include <string>

/**
 * Entry point of the program
 * Starts the application run loop
 */
int main() {
    Utils::enableVirtualTerminalProcessing();
    cv::utils::logging::setLogLevel(
            cv::utils::logging::LOG_LEVEL_WARNING);
    std::cout << std::endl;
    Utils::addSeparator();
    std::cout << "\033[1;34m" << "Pixalyze 2024" << "\033[0m" <<
    " - By: Landon Prince" << std::endl;
    Utils::addSeparator();
    std::cout << "Enter 'help' for command information" << std::endl;
    Utils::addSeparator();
    try {
        ImageManager im;
        CommandTrie ct;
        CommandFactory factory(&im, &ct);

        bool runLoopFlag = true;
        while (runLoopFlag) {
            std::string input;
            std::getline(std::cin, input);
            if (std::cin.fail()) {
                Utils::addSeparator();
                std::cout << "Invalid input" << std::endl;
                Utils::addSeparator();
                std::terminate();
            }
            try {
                Command cmd = factory.makeCommand(input);
                runLoopFlag = cmd.execute();
            } catch (std::exception& ex) {
                Utils::addSeparator();
                std::cout << "\033[1;31m" << "Command error: " << "\033[0m"
                << ex.what() << std::endl;
                Utils::addSeparator();
            }
        }
    } catch (std::exception& ex) {
        Utils::addSeparator();
        std::cout << "Startup error: " << ex.what() << std::endl;
        Utils::addSeparator();
    }
}
