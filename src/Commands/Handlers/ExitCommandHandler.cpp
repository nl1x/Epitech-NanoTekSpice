//
// Created by elies on 2/28/25.
//

#include "ExitCommandHandler.hpp"
#include <iostream>

bool ExitCommandHandler::execute(CommandProcessor &processor, const std::string &commandLine) {
    (void)processor;
    (void)commandLine;
    return false;
}