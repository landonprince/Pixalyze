// By: Landon Prince (5/15/2024)

#ifndef PIXALYZE_CONTOURS_COMMAND_H
#define PIXALYZE_CONTOURS_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to apply contour detection
 * @extends CommandImpl
 */
class ContoursCommand final : public CommandImpl {
public:
    ContoursCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~ContoursCommand() override = default;
    ContoursCommand(const ContoursCommand&) = default;
    ContoursCommand& operator=(const ContoursCommand&) = default;

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
    explicit ContoursCommand(ImageManager* im);
};

#endif //PIXALYZE_CONTOURS_COMMAND_H
