// By: Landon Prince (5/15/2024)

#ifndef PIXALYZE_HISTOGRAM_COMMAND_H
#define PIXALYZE_HISTOGRAM_COMMAND_H

#include "command_impl.h"

/**
 * Represents a request to create histogram of loaded image
 * @extends CommandImpl
 */
class HistogramCommand final : public CommandImpl {
public:
    HistogramCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~HistogramCommand() override = default;
    HistogramCommand(const HistogramCommand&) = default;
    HistogramCommand& operator=(const HistogramCommand&) = default;

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
    explicit HistogramCommand(ImageManager* im);
};

#endif //PIXALYZE_HISTOGRAM_COMMAND_H
