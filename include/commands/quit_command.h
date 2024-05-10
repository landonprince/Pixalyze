// By: Landon Prince (5/10/2024)

#ifndef PIXALYZE_QUIT_COMMAND_H
#define PIXALYZE_QUIT_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to quit the application
 * @extends CommandImpl
 */
class QuitCommand final : public CommandImpl {
public:
    QuitCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~QuitCommand() override = default;
    QuitCommand(const QuitCommand&) = default;
    QuitCommand& operator=(const QuitCommand&) = default;

    /**
     * Execute the command
     * @return True if success, false otherwise (ends run loop)
     */
     bool execute() override;

    /**
     * Static method to print out help for the command
     */
    static void help();

private:
    friend class CommandFactory; // to enable command creation


    /**
     * Primary constructor
     * @param db database against which it executes
     */
     explicit QuitCommand(ImageManager* im);
};

#endif //PIXALYZE_QUIT_COMMAND_H
