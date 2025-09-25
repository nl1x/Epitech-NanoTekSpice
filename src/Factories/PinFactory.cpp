/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** PinFactory.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Factories/PinFactory.hpp"
#include "Pins/PinOutput.hpp"
#include "Pins/PinInput.hpp"
#include "Pins/Interface/IPin.hpp"

std::shared_ptr<nts::IPin> nts::PinFactory::createPin(const IPin::PinType type, IComponent &component)
{
    switch (type) {
        case IPin::INPUT:
            return std::make_shared<PinInput>(component);
        case IPin::OUTPUT:
            return std::make_shared<PinOutput>(component);
        case IPin::UNDEFINED:
            return nullptr;
    }
    return nullptr;
}
