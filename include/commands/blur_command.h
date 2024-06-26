// By: Landon Prince (5/13/2024)

#ifndef PIXALYZE_BLUR_COMMAND_H
#define PIXALYZE_BLUR_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to display a loaded image
 * @extends CommandImpl
 */
class BlurCommand final : public CommandImpl {
public:
    BlurCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~BlurCommand() override = default;
    BlurCommand(const BlurCommand&) = default;
    BlurCommand& operator=(const BlurCommand&) = default;

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
    explicit BlurCommand(ImageManager* im);
};

#endif //PIXALYZE_BLUR_COMMAND_H
