// By: Landon Prince (5/13/2024)

#ifndef PIXALYZE_SAVE_COMMAND_H
#define PIXALYZE_SAVE_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to save a loaded image
 * @extends CommandImpl
 */
class SaveCommand final : public CommandImpl {
public:
    SaveCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~SaveCommand() override = default;
    SaveCommand(const SaveCommand&) = default;
    SaveCommand& operator=(const SaveCommand&) = default;

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
    explicit SaveCommand(ImageManager* im);
};

#endif //PIXALYZE_SAVE_COMMAND_H
