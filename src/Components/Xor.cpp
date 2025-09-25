/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Xor.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Components/Xor.hpp"

nts::Xor::Xor(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "xor.nts", name)
{}

void nts::Xor::compute()
{
    // Todo: implement this method
    // Author: Elie
    this->updateInputPins();
    auto a = getPin(1)->getValue();
    auto b = getPin(2)->getValue();
    auto output = getPin(3);

    if (a == nts::Undefined || b == nts::Undefined)
        output->setValue(nts::Undefined);
    else if (a == b)
        output->setValue(nts::False);
    else
        output->setValue(nts::True);
}

