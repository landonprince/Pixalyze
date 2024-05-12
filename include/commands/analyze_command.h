// By: Landon Prince (5/12/2024)

#ifndef PIXALYZE_ANALYZE_COMMAND_H
#define PIXALYZE_ANALYZE_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to load in an image
 * @extends CommandImpl
 */
class AnalyzeCommand final : public CommandImpl {
public:
    AnalyzeCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~AnalyzeCommand() override = default;
    AnalyzeCommand(const AnalyzeCommand&) = default;
    AnalyzeCommand& operator=(const AnalyzeCommand&) = default;

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
    AnalyzeCommand(ImageManager* im);
};

#endif //PIXALYZE_ANALYZE_COMMAND_H
