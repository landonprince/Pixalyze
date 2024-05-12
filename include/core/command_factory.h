// By: Landon Prince (5/10/2024)

#ifndef PIXALYZE_COMMAND_FACTORY_H
#define PIXALYZE_COMMAND_FACTORY_H

#include "commands/command.h"
#include "commands/command_trie.h"
#include <deque>
#include <string>

class ImageManager;
class CommandTrie;

/**
 * CommandFactory class allows creation of command
 * objects that act on an ImageManager
 */
class CommandFactory {
public:
    CommandFactory() = delete; // must construct with ImageManager

    /**
     * Primary constructor
     * @param im ImageManager against which to operate
     */
    CommandFactory(ImageManager* im, CommandTrie* ct);

    /**
    * Register all commands with the CommandTrie
    */
    void registerCommands();

    /**
     * Takes user input and creates appropriate command
     * @param input user input string
     * @return command ready for execution
     */
    Command makeCommand(const std::string& input);

    /**
     * Make a quit command
     * @return QuitCommand instance (fully bridged)
     */
    Command makeQuit();

    /**
     * Make a help command
     * @return HelpCommand instance (fully bridged)
     */
    Command makeHelp();

    /**
     * Make a help command
     * @return LoadCommand instance (fully bridged)
     */
    Command makeLoad();

    /**
    * Make a show command
    * @return ShowCommand instance (fully bridged)
    */
    Command makeShow();

    /**
    * Make a analyze command
    * @return AnalyzeCommand instance (fully bridged)
    */
    Command makeAnalyze();

private:
    ImageManager* im; // ImageManager against which to execute
    CommandTrie* ct; // CommandTrie to get commands
    std::deque<std::string> params;
};

#endif //PIXALYZE_COMMAND_FACTORY_H
