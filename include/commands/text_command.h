// By: Landon Prince (5/14/2024)

#ifndef PIXALYZE_TEXT_COMMAND_H
#define PIXALYZE_TEXT_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to add text to a loaded image
 * @extends CommandImpl
 */
class TextCommand final : public CommandImpl {
public:
    TextCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~TextCommand() override = default;
    TextCommand(const TextCommand&) = default;
    TextCommand& operator=(const TextCommand&) = default;

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
    std::string text;
    std::string color;
    double fontSize;

    /**
     * Primary constructor
     * @param im ImageManager against which it executes
     */
    TextCommand(ImageManager* im, const std::deque<std::string>& params);
};

#endif //PIXALYZE_TEXT_COMMAND_H
