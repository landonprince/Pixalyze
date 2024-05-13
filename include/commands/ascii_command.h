// By: Landon Prince (5/13/2024)

#ifndef PIXALYZE_ASCII_COMMAND_H
#define PIXALYZE_ASCII_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to save ascii art of a loaded image
 * @extends CommandImpl
 */
class AsciiCommand final : public CommandImpl {
public:
    AsciiCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~AsciiCommand() override = default;
    AsciiCommand(const AsciiCommand&) = default;
    AsciiCommand& operator=(const AsciiCommand&) = default;

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
    explicit AsciiCommand(ImageManager* im);
};




#endif //PIXALYZE_ASCII_COMMAND_H
