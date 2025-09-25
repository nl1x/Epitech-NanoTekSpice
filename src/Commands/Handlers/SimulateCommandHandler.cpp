//
// Created by elies on 2/28/25.
//

#include "SimulateCommandHandler.hpp"
#include <iostream>
#include "Pins/PinOutput.hpp"

bool nts::SimulateCommandHandler::execute(CommandProcessor &processor, const std::string &commandLine) {
    (void)processor;
    (void)commandLine;

    resetChecks();
    core_.applyWaitingCommands();
    computeAllOutputs();

    core_.incrementThicks();
    return true;
}

// Étape 1: Réinitialiser les checks pour éviter les calculs multiples
void nts::SimulateCommandHandler::resetChecks() const
{
    for (const auto &comp : core_.getOuts())
        comp.second->resetCheck();
}

// Étape 3: Parcourir tous les outputs et déclencher les computes
void nts::SimulateCommandHandler::computeAllOutputs() const
{
    for (const auto &clock : core_.getClocks()) {
        clock.second->update();
    }
    for (const auto &output : core_.getOuts()) {
        output.second->compute();
        output.second->check();
    }
    for (const auto &logger : core_.getLoggers()) {
        logger.second->compute();
    }
}
