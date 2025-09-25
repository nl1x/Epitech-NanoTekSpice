/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** ComponentAnd.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Components/And.hpp"
#include <iostream>

nts::And::And(const std::string &name): AComponent(COMPONENT_CONFIG_FOLDER + "and.nts", name)
{}

void nts::And::compute() {
    this->updateInputPins();

    auto a = getPin(1)->getValue();
    auto b = getPin(2)->getValue();
    auto output = getPin(3);

    if (a == nts::True && b == nts::True)
        output->setValue(nts::True);
    else if (a == nts::False || b == nts::False)
        output->setValue(nts::False);
    else
        output->setValue(nts::Undefined);
}
