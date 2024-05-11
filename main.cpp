// By: Landon Prince (5/10/2024)

#include "core/image_manager.h"
#include "core/command_factory.h"
#include "commands/command.h"
#include <iostream>
#include <string>

/**
 * Entry point of the program
 * Starts the system run loop
 */
int main() {
    try {
        ImageManager im;
        CommandFactory factory(&im);

        bool runLoopFlag = true;
        while (runLoopFlag) {
            std::string input;
            std::getline(std::cin, input);
            if (std::cin.fail()) {
                std::cerr << "invalid input" << std::endl;
                std::terminate();
            }
            try {
                Command cmd = factory.makeCommand(input);
                runLoopFlag = cmd.execute();
            } catch (std::exception& e) {
                std::cout << "command error: " << e.what() << std::endl;
            }
        }
    } catch (std::exception& e) {
        std::cout << "startup error: " << e.what() << std::endl;
    }
}
