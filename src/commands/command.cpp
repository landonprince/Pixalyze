// By: Landon Prince (5/10/2024)

#include "commands/command.h"
#include "commands/command_impl.h"

Command::Command(CommandImpl* command)
        : bridge(command) {}

Command::~Command() {
    delete bridge;
}

bool Command::execute() {
    return bridge->execute();
}
