/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** TriState.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Components/TriState.hpp"

nts::TriState::TriState(const std::string& name):
    AComponent(COMPONENT_CONFIG_FOLDER + "tristate.nts", name)
{}

void nts::TriState::compute()
{
    this->updateInputPins();

    const auto a = getPin(1)->getValue();
    const auto b = getPin(2)->getValue();
    const auto output = getPin(3);

    if (b == True)
        output->setValue(a);
    else
        output->setValue(Undefined);
}
