/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** APin.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "APin.hpp"

nts::APin::APin(IComponent &component, const PinType type):
    type_m(type), value_(Undefined), component_m(component)
{}

nts::IComponent &nts::APin::getComponent()
{
    return this->component_m;
}

nts::Tristate nts::APin::getValue()
{
    return this->value_;
}

nts::IPin::PinType nts::APin::getType()
{
    return this->type_m;
}
