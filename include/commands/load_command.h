// By: Landon Prince (5/11/2024)

#ifndef PIXALYZE_LOAD_COMMAND_H
#define PIXALYZE_LOAD_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to load in an image
 * @extends CommandImpl
 */
class LoadCommand final : public CommandImpl {
public:
    LoadCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~LoadCommand() override = default;
    LoadCommand(const LoadCommand&) = default;
    LoadCommand& operator=(const LoadCommand&) = default;

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
    LoadCommand(ImageManager* im, const std::deque<std::string>& params);

    std::string imagePath;

};

#endif //PIXALYZE_LOAD_COMMAND_H
