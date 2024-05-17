// By: Landon Prince (5/10/2024)

#ifndef PIXALYZE_COMMAND_H
#define PIXALYZE_COMMAND_H

class CommandImpl;

/**
 * Command class provides abstracted interface for commands
 * Left-hand side of the bridge for the command pattern
 */
class Command {
public:
    Command() = delete; // only command factory makes commands
    ~Command();

    // disallow copy and assignment operations
    Command(const Command&) = delete;
    Command& operator=(const Command&) = delete;

    /**
     * Allow anyone with access to execute the command
     * @return True if success, false otherwise (ends run loop)
     */
    bool execute();

private:
    friend class CommandFactory; // to enable command creation

    /**
     * Primary constructor
     * @param impl right-side of the bridge
     */
    explicit Command(CommandImpl* impl);

    CommandImpl* bridge; // right-side of bridge
};

#endif //PIXALYZE_COMMAND_H
