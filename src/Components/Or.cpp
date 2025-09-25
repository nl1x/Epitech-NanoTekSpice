/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Or.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Components/Or.hpp"

nts::Or::Or(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "or.nts", name)
{}

void nts::Or::compute() {
    this->updateInputPins();

    auto a = getPin(1)->getValue();
    auto b = getPin(2)->getValue();
    auto output = getPin(3);

    if (a == nts::True || b == nts::True) {
        output->setValue(nts::True);
    } else if (a == nts::Undefined || b == nts::Undefined) {
        output->setValue(nts::Undefined);
    } else {
        output->setValue(nts::False);
    }
}
