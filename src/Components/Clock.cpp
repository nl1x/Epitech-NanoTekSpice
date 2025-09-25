/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Clock.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Components/Clock.hpp"

nts::Clock::Clock(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "clock.nts", name)
{}

void nts::Clock::compute()
{}

void nts::Clock::update()
{
    this->updateInputPins();

    auto pin = getPin(1);

    if (pin->getValue() != nts::Undefined)
        pin->setValue(pin->getValue() == nts::True ? False : True);
}
