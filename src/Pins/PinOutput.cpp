/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** PinOutput.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Pins/PinOutput.hpp"
#include "Pins/PinInput.hpp"
#include <iostream>

nts::PinOutput::PinOutput(IComponent &component):
    APin(component, OUTPUT)
{}

void nts::PinOutput::link(const std::shared_ptr<IPin> pin)
{
    if (pin->getType() == OUTPUT)
        throw InvalidPinTypeError("An output pin cannot be linked to another output pin.");

    const std::shared_ptr<PinInput> pinInput = std::dynamic_pointer_cast<PinInput>(pin);

    if (pinInput == nullptr)
        throw InvalidPinTypeError("An output pin can only be linked to an input pin.");

    this->_links.push_back(pinInput);
}

std::shared_ptr<nts::IPin> nts::PinOutput::getLink(size_t pin)
{
    if (pin > this->_links.size())
        throw OutOfBoundError("A pin input have only 1 linked pin.");

    auto iter = this->_links.begin();
    for (size_t i = -1; i < pin; i++) {
        ++iter;
    }
    return *iter;
}

size_t nts::PinOutput::nbLinks()
{
    return this->_links.size();
}
