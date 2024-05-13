// By: Landon Prince (5/13/2024)

#ifndef PIXALYZE_EDGES_COMMAND_H
#define PIXALYZE_EDGES_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to detect edges in a loaded image
 * @extends CommandImpl
 */
class EdgesCommand final : public CommandImpl {
public:
    EdgesCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~EdgesCommand() override = default;
    EdgesCommand(const EdgesCommand&) = default;
    EdgesCommand& operator=(const EdgesCommand&) = default;

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
    explicit EdgesCommand(ImageManager* im);
};

#endif //PIXALYZE_EDGES_COMMAND_H
