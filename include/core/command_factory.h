// By: Landon Prince (5/10/2024)

#ifndef PIXALYZE_COMMAND_FACTORY_H
#define PIXALYZE_COMMAND_FACTORY_H

#include "commands/command.h"
#include <deque>
#include <string>

class ImageManager;

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
    explicit CommandFactory(ImageManager* im);

    /**
     * Takes user input and creates appropriate command
     * - responsible for:
     *     - Determining which command is being requested
     *     - Marshalling command parameters
     *     - Creating both left and right side of bridge
     * @param input user input string
     * @return command ready for execution
     */
    Command makeCommand(const std::string& input);

    /**
     * Make a quit command
     * @return QuitCommand instance (fully bridged)
     */
    Command makeQuit();

private:
    ImageManager* im; // ImageManager against which to execute
};

#endif //PIXALYZE_COMMAND_FACTORY_H
