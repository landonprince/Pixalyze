// By: Landon Prince (5/12/2024)

#ifndef PIXALYZE_GRAY_COMMAND_H
#define PIXALYZE_GRAY_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to turn a loaded image to grayscale
 * @extends CommandImpl
 */
class GrayCommand final : public CommandImpl {
public:
    GrayCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~GrayCommand() override = default;
    GrayCommand(const GrayCommand&) = default;
    GrayCommand& operator=(const GrayCommand&) = default;

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
    explicit GrayCommand(ImageManager* im);
};

#endif //PIXALYZE_GRAY_COMMAND_H
