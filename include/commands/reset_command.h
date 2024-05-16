// By: Landon Prince (5/15/2024)

#ifndef PIXALYZE_RESET_COMMAND_H
#define PIXALYZE_RESET_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to reset loaded image
 * @extends CommandImpl
 */
class ResetCommand final : public CommandImpl {
public:
    ResetCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~ResetCommand() override = default;
    ResetCommand(const ResetCommand&) = default;
    ResetCommand& operator=(const ResetCommand&) = default;

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
    explicit ResetCommand(ImageManager* im);
};

#endif //PIXALYZE_RESET_COMMAND_H
