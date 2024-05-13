// By: Landon Prince (5/10/2024)

#include "core/image_manager.h"
#include "core/command_factory.h"
#include <opencv2/core/utils/logger.hpp>
#include <iostream>
#include <string>

/**
 * Entry point of the program
 * Starts the application run loop
 */
int main() {
    cv::utils::logging::setLogLevel(
            cv::utils::logging::LOG_LEVEL_WARNING);
    try {
        ImageManager im;
        CommandTrie ct;
        CommandFactory factory(&im, &ct);

        bool runLoopFlag = true;
        while (runLoopFlag) {
            std::string input;
            std::getline(std::cin, input);
            if (std::cin.fail()) {
                std::cout << "invalid input" << std::endl;
                std::terminate();
            }
            try {
                Command cmd = factory.makeCommand(input);
                runLoopFlag = cmd.execute();
            } catch (std::exception& ex) {
                std::cout << "command error: " << ex.what() << std::endl;
            }
        }
    } catch (std::exception& ex) {
        std::cout << "startup error: " << ex.what() << std::endl;
    }
}
