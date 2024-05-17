// By: Landon Prince (5/10/2024)

#ifndef PIXALYZE_COMMAND_IMPL_H
#define PIXALYZE_COMMAND_IMPL_H

#include <deque>
#include <ostream>

class ImageManager;

/**
 * CommandImpl class provides implementation for commands
 * Base class for right-hand side of bridge pattern
 */
class CommandImpl {
public:
    CommandImpl() = delete; // can only construct with ImageManager ptr

    /**
     * Primary constructor
     * @param db pointer to database against which to execute
     */
    explicit CommandImpl(ImageManager* im) : im(im) {}

    virtual ~CommandImpl() = default; // virtual for polymorphic destruction

    /**
     * Execution interface for all derived Command classes
     * @return True if success, false otherwise (ends run loop)
     */
    virtual bool execute() = 0;

protected:
    ImageManager* im; // ImageManager command should execute against
};

#endif //PIXALYZE_COMMAND_IMPL_H
