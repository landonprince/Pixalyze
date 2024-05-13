// By: Landon Prince (5/12/2024)

#ifndef PIXALYZE_COLOR_COMMAND_H
#define PIXALYZE_COLOR_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to turn a loaded image to grayscale
 * @extends CommandImpl
 */
class ColorCommand final : public CommandImpl {
public:
    ColorCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~ColorCommand() override = default;
    ColorCommand(const ColorCommand&) = default;
    ColorCommand& operator=(const ColorCommand&) = default;

    /**
     * Execute the command
     * @return True if success, false otherwise (ends run loop)
     */
    bool execute() override;

    /**
     * Static method to print out help for the command
     */
    static void help();

    friend class CommandFactory; // to enable command creation

private:
    /**
     * Primary constructor
     * @param im ImageManager against which it executes
     */
    explicit ColorCommand(ImageManager* im);
};
#endif //PIXALYZE_COLOR_COMMAND_H
