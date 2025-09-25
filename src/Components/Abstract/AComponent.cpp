/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** AComponent.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Error/Error.hpp"
#include "Components/Abstract/AComponent.hpp"
#include "Factories/PinFactory.hpp"
#include <utility>

nts::AComponent::AComponent(std::string name):
    _isCheck(false), name_m(std::move(name))
{}

nts::AComponent::AComponent(const std::string &filePath, const std::string &name):
    _isCheck(false), name_m(name)
{
    this->AComponent::parseFile(filePath);
}

void nts::AComponent::createPins(const std::map<size_t, IPin::PinType> &pinsType)
{
    for (const auto [pinId, pinType] : pinsType)
        this->_pins.push_back(PinFactory::createPin(pinType, *this));
}

void nts::AComponent::updateInputPins()
{
    for (const auto &pin : this->_pins) {
        if (pin->getType() != IPin::INPUT)
            continue;
        if (pin->nbLinks() >= 1) {
            const auto linkedPin = pin->getLink(1);
            if (!linkedPin->getComponent().isChecked()) {
                linkedPin->getComponent().compute();
                linkedPin->getComponent().check();
            }
            this->check();
            pin->setValue(linkedPin->getValue());
        }
    }
}

std::string nts::AComponent::getName() {
    return this->name_m;
}

std::shared_ptr<nts::IPin> nts::AComponent::getPin(const std::size_t pin)
{
    if (pin > this->_pins.size())
        throw OutOfBoundError("Cannot access pin n°" + Parser::toString(pin) + " because the component '" + this->getName() + "' have only " + Parser::toString(this->_pins.size()) + " pins.");
    return this->_pins[pin - 1];
}

void nts::AComponent::parseFile(const std::string& filePath)
{
    const Parser parser(filePath);

    this->createPins(parser.getPins());
}

void nts::AComponent::setLink(const std::size_t pin, IComponent& other, const std::size_t otherPin)
{
    const std::shared_ptr<IPin> otherPinObj = other.getPin(otherPin);
    const std::shared_ptr<IPin> pinObj = this->getPin(pin);

    otherPinObj->link(pinObj);
    pinObj->link(otherPinObj);
}

void nts::AComponent::check()
{
    this->_isCheck = true;
}

bool nts::AComponent::isChecked()
{
    return this->_isCheck;
}

void nts::AComponent::resetCheck()
{
    if (!this->isChecked())
        return;

    this->_isCheck = false;
    for (const auto &pin : this->_pins) {
        if (pin->getType() != IPin::INPUT)
            continue;
        if (pin->nbLinks() >= 1) {
            const auto linkedPin = pin->getLink(1);
            if (linkedPin->getComponent().isChecked()) {
                linkedPin->getComponent().resetCheck();
            }
        }
    }
}
