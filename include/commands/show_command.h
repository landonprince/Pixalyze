// By: Landon Prince (5/11/2024)

#ifndef PIXALYZE_SHOW_COMMAND_H
#define PIXALYZE_SHOW_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to load in an image
 * @extends CommandImpl
 */
class ShowCommand final : public CommandImpl {
public:
    ShowCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~ShowCommand() override = default;
    ShowCommand(const ShowCommand&) = default;
    ShowCommand& operator=(const ShowCommand&) = default;

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
    std::string imagePath;

    /**
     * Primary constructor
     * @param im ImageManager against which it executes
     */
    explicit ShowCommand(ImageManager* im);
};


#endif //PIXALYZE_SHOW_COMMAND_H
