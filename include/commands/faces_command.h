// By: Landon Prince (5/15/2024)

#ifndef PIXALYZE_FACES_COMMAND_H
#define PIXALYZE_FACES_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to detect faces in loaded image
 * @extends CommandImpl
 */
class FacesCommand final : public CommandImpl {
public:
    FacesCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~FacesCommand() override = default;
    FacesCommand(const FacesCommand&) = default;
    FacesCommand& operator=(const FacesCommand&) = default;

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
    explicit FacesCommand(ImageManager* im);
};

#endif //PIXALYZE_FACES_COMMAND_H
