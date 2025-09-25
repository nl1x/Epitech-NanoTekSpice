/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** PinInput.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Pins/PinInput.hpp"

nts::PinInput::PinInput(IComponent &component):
    APin(component, INPUT)
{}

void nts::PinInput::link(const std::shared_ptr<IPin> pin)
{
    if (pin->getType() == INPUT)
        throw InvalidPinTypeError("An input pin cannot be linked to another input pin.");

    if (!this->link_.expired())
        throw Error("This input pin is already linked to another pin.");
    
    this->link_ = std::dynamic_pointer_cast<PinOutput>(pin);
    if (this->link_.expired())
        throw InvalidPinTypeError("An input pin can only be linked to an output pin.");
}

std::shared_ptr<nts::IPin> nts::PinInput::getLink(size_t pin)
{
    if (pin > 1)
        throw OutOfBoundError("A pin input have only 1 linked pin.");

    return this->link_.lock();
}

size_t nts::PinInput::nbLinks()
{
    return !this->link_.expired();
}
