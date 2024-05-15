// By: Landon Prince (5/11/2024)

#ifndef PIXALYZE_COMMAND_TRIE_H
#define PIXALYZE_COMMAND_TRIE_H

#include <unordered_map>
#include <set>
#include <functional>
#include <string>
#include "command.h"
#include <memory>

/**
 * CommandNode class acts as a single command in the trie
 */
class CommandNode {
public:
    std::unordered_map<char, std::shared_ptr<CommandNode>> children;
    std::function<void()> helpFunction; // for HelpCommand
    std::function<Command()> factoryFunction; // for CommandFactory

    /**
     * Primary constructor - sets both functions to nullptr
     */
    CommandNode() : helpFunction(nullptr), factoryFunction(nullptr) {}
};

/**
 * CommandTrie class provides trie structure for all commands
 */
class CommandTrie {
public:
    /**
     * Primary constructor - initializes root node
     */
    CommandTrie();

    /**
     * Adds a command (with its associated methods) into the trie
     * @param command - name of command
     * @param helpFunc - command's help method
     * @param factoryFunc - command's factory method
     */
    void registerCommand(const std::string &command, void (*helpFunc)(),
                         std::function<Command()> factoryFunc);

    /**
     * Finds command in trie and calls its help method
     * example: calls QuitCommand::help()
     * @param command - command name
     */
    std::function<void()> findHelp(const std::string &command);

    /**
     * Finds command in trie and calls its factory method
     * example: calls CommandFactory::makeQuit()
     * @param command - command name
     */
    std::function<Command()> findFactory(const std::string &command);

    /**
     * Finds command in trie and calls its factory method
     * @return set of registered command names
     */
    [[nodiscard]] const std::set<std::string>& getCommands() const;

    /**
     * prints all available commands
     */
    void printCommands() const;

private:
    std::shared_ptr<CommandNode> root;
    std::set<std::string> commands; // set of registered command names
};

#endif //PIXALYZE_COMMAND_TRIE_H
