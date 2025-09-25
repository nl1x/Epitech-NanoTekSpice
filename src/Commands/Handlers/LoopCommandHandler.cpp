//
// Created by elies on 2/28/25.
//

#include <csignal>
#include <iostream>
#include <unistd.h>
#include "Core/Core.hpp"
#include "LoopCommandHandler.hpp"
#include "Error/Error.hpp"
#include "Commands/CommandProcessor.hpp"

volatile bool LOOP_RUNNING = true;

void LoopCommandHandler::handleSignal(int signal) {
    if (signal == SIGINT) {
        std::cout << std::endl;
        LOOP_RUNNING = false;
    }
}

bool LoopCommandHandler::execute(CommandProcessor &processor, const std::string &commandLine)
{
    (void)processor;
    (void)commandLine;

    LOOP_RUNNING = true;
    while (LOOP_RUNNING) {
        std::signal(SIGINT, handleSignal);
        try {
            processor.processCommand("simulate");
            processor.processCommand("display");
        } catch (const nts::RuntimeError &err) {
            std::cerr << "[RUNTIME ERROR] " << err.what() << std::endl;
        }
        usleep(1000000);
    }
    return true;
}
