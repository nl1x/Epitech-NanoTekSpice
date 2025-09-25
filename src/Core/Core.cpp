/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Core.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Core/Core.hpp"

#include <fstream>
#include <iostream>
#include "Commands/CommandProcessor.hpp"
#include "Error/Error.hpp"

// Variable globale pour gérer les signaux
volatile bool RUNNING = true;

// Gestionnaire de signal pour Ctrl+C

nts::Core::Core(const std::string &filePath):
    parser_m(Parser(filePath)), thicks_(0)
{
    this->retrieveParserData();
}

void nts::Core::retrieveParserData()
{
    this->ins_ = this->parser_m.getInputs();
    this->outs_ = this->parser_m.getOutputs();
    this->clocks_ = this->parser_m.getClocks();
    this->components_ = this->parser_m.getComponents();
    this->loggers_ = this->parser_m.getLoggers();

    if (this->components_.empty() && this->ins_.empty() && this->outs_.empty() && this->clocks_.empty())
        throw ParserError("The configuration file '" + this->parser_m.getFilename() + "' does not provide any chipset.");
}

nts::Core::~Core()
{}

void nts::Core::addCommand(const std::pmr::string &name, Tristate state) {
    waiting_commands_.emplace(name, state);
}

// check les ins + les clock ?
void nts::Core::applyWaitingCommands() {
    while (!waiting_commands_.empty()) {
        auto [inptName, value] = waiting_commands_.front();
        waiting_commands_.pop();

        auto found_clocks = clocks_.find(inptName);
        auto found_ins = ins_.find(inptName);

        if (found_clocks == clocks_.end() && found_ins == ins_.end()) {
            throw RuntimeError("Invalid input name: " + inptName);
        } else if (found_clocks != clocks_.end()) {
            found_clocks->second->getPin(1)->setValue(value == False ? True : value == True ? False : Undefined); // reverse its value due to the computing that will come after
        } else {
            found_ins->second->getPin(1)->setValue(value);
        }
    }
}

void nts::Core::run()
{
    this->thicks_ = -1;
    CommandProcessor processor(*this);

    processor.processCommand("simulate");
    while (RUNNING) {

        // afficher le prompt
        std::cout << "> " << std::flush;
        std::string command;

        // lire la commande + handle le Ctrl D
        if (!std::getline(std::cin, command)) {
            break;
        }

        try {
            if (!processor.processCommand(command))
                break;
        } catch (const RuntimeError &err) {
            std::cerr << "[RUNTIME ERROR] " << err.what() << std::endl;
        }
    }
}
