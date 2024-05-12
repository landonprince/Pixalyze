// By: Landon Prince (5/10/2024)

#ifndef PIXALYZE_HELP_COMMAND_H
#define PIXALYZE_HELP_COMMAND_H

#include "command_impl.h"
#include "commands/command_trie.h"

class CommandTrie;

/**
 * Represents a request to obtain help
 * @extends CommandImpl
 */
class HelpCommand final : public CommandImpl {
public:
    HelpCommand() = delete; // only allow factory to create

    // Default destructor, copy-constructor and assignment
    ~HelpCommand() override = default;
    HelpCommand(const HelpCommand&) = default;
    HelpCommand& operator=(const HelpCommand&) = default;

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
    CommandTrie* ct;
    std::string commandName;

    /**
     * Primary constructor
     * @param im ImageManager against which it executes
     * @param ct CommandTrie to use commands
     * @param im params for the command
     */
    HelpCommand(ImageManager* im, CommandTrie* ct, const std::deque<std::string>& params);
};

#endif //PIXALYZE_HELP_COMMAND_H
