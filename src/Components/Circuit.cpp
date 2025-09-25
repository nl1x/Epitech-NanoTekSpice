/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** ComponentCircuit.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Components/Circuit.hpp"
#include "Factories/PinFactory.hpp"
#include "Pins/PinOutput.hpp"

nts::Circuit::Circuit(const std::string &filename, const std::string &name):
    AComponent(name)
{
    this->parseFile(COMPONENT_CONFIG_FOLDER + filename);
}

void nts::Circuit::compute()
{}

void nts::Circuit::parseFile(const std::string &filePath)
{
    const Parser parser(filePath);

    this->components_ = parser.getComponents();
    this->createSelfPins(parser.getPins(), parser.getSelfPins());
}

void nts::Circuit::createSelfPins(std::map<size_t, IPin::PinType> pins, std::map<size_t, Parser::Link> selfPins)
{
    bool done = false;
    size_t id = 1;

    while (!done) {
        auto pin = pins.find(id);
        auto selfPin = selfPins.find(id);

        if (pin != pins.end()) {
            this->_pins.push_back(PinFactory::createPin(pin->second, *this));
        } else if (selfPin != selfPins.end()) {
            const auto component = this->getComponent(selfPin->second.getName());
            this->_pins.push_back(component->getPin(selfPin->second.getPinID()));
        } else
            done = true;
        id++;
    }
}

std::shared_ptr<nts::IComponent> nts::Circuit::getComponent(const std::string& name)
{
    const auto component = this->components_.find(name);

    if (component == this->components_.end())
        throw RuntimeError("Circuit '" + this->getName() + "' has no component named " + name);
    return component->second;
}
