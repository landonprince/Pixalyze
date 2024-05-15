// By: Landon Prince (5/10/2024)

#include "commands/command_trie.h"
#include <iostream>
#include <iomanip>

CommandTrie::CommandTrie() : root(std::make_shared<CommandNode>()) {}

void CommandTrie::registerCommand(const std::string &command, void (*helpFunc)(),
                                  std::function<Command()> factoryFunc) {
    auto current = root;
    for (char ch : command) {
        if (!current->children.count(ch)) {
            current->children[ch] = std::make_shared<CommandNode>();
        }
        current = current->children[ch];
    }
    current->helpFunction = helpFunc;
    current->factoryFunction = std::move(factoryFunc);
    commands.insert(command);
}

std::function<void()> CommandTrie::findHelp(const std::string &command) {
    auto current = root;
    for (char ch : command) {
        if (!current->children.count(ch)) return nullptr;
        current = current->children[ch];
    }
    return current->helpFunction;
}

std::function<Command()> CommandTrie::findFactory(const std::string &command) {
    auto current = root;
    for (char ch : command) {
        if (!current->children.count(ch)) return nullptr;
        current = current->children[ch];
    }
    return current->factoryFunction;
}

const std::set<std::string>& CommandTrie::getCommands() const {
    return commands;
}

void CommandTrie::printCommands() const {
    const int columnWidth = 20;
    int count = 0;
    for (const auto& command : commands) {
        std::cout << std::setw(columnWidth) << std::left << command;
        count++;
        if (count % 4 == 0) {
            std::cout << std::endl;
        }
    }
    if (count % 4 != 0) {
        std::cout << std::endl;
    }
}

