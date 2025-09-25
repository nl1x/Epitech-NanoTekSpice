/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Not.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Components/Not.hpp"

nts::Not::Not(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "not.nts", name)
{}

void nts::Not::compute()
{
    // Todo: implement this method
    // Author: Elie
    this->updateInputPins();

    auto in = getPin(1)->getValue();
    auto out = getPin(2);

    if (in == nts::Undefined)
        out->setValue(nts::Undefined);
    else
        out->setValue(in == nts::True ? nts::False : nts::True);
}
