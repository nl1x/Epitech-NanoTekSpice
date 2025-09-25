//
// Created by elies on 2/28/25.
//

#include "DisplayCommandHandler.hpp"
#include <iostream>

char DisplayCommandHandler::tristateToChar(nts::Tristate state) const {
    switch (state) {
        case nts::False: return '0';
        case nts::True: return '1';
        default: return 'U';
    }
}


bool DisplayCommandHandler::execute(CommandProcessor &processor, const std::string &commandLine) {
    (void)processor;
    (void)commandLine;

    std::cout << "tick: " << core_.getThicks() << std::endl;

    std::cout << "input(s):" << std::endl;
    for (auto &clock : core_.getClocks()) {
        auto pin = clock.second->getPin(1);
        std::cout << "  " << clock.first << ": " << tristateToChar(pin->getValue()) << std::endl;
    }

    for (auto &input : core_.getIns()) {

        auto pin = input.second->getPin(1);
        std::cout << "  " << input.first << ": " << tristateToChar(pin->getValue()) << std::endl;

    }

    std::cout << "output(s):" << std::endl;
    for (auto &output : core_.getOuts()) {
        auto pin = output.second->getPin(1);
        std::cout << "  " << output.first << ": " << tristateToChar(pin->getValue()) << std::endl;
    }
    return true;
}