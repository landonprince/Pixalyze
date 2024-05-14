// By: Landon Prince (5/13/2024)

#ifndef PIXALYZE_SMOOTH_COMMAND_H
#define PIXALYZE_SMOOTH_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to load in an image
 * @extends CommandImpl
 */
class SmoothCommand final : public CommandImpl {
public:
    SmoothCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~SmoothCommand() override = default;
    SmoothCommand(const SmoothCommand&) = default;
    SmoothCommand& operator=(const SmoothCommand&) = default;

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
    int intensity;

    /**
     * Primary constructor
     * @param im ImageManager against which it executes
     */
    SmoothCommand(ImageManager* im, const std::deque<std::string>& params);
};

#endif //PIXALYZE_SMOOTH_COMMAND_H
