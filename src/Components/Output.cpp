/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Output.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Components/Output.hpp"
#include <iostream>

nts::Output::Output(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "output.nts", name)
{}

void nts::Output::compute()
{
    this->updateInputPins();
    // const auto &inputPin = this->getPin(1);
    // if (inputPin->nbLinks() >= 1) {
        // const auto &link = inputPin->getLink(1);
        // if (!link->getComponent().isChecked()) {
            // link->getComponent().compute(); // Computing linked component
            // link->getComponent().check();
        // }
        // inputPin->setValue(link->getValue()); // Updating  pin input to linked pin output
    // }
}
