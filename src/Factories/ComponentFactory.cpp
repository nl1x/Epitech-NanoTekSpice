/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** ComponentFactory.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Factories/ComponentFactory.hpp"
#include "Components/Buffer.hpp"
#include "Components/Circuit.hpp"

std::shared_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &component, const std::string &name)
{
    if (component == "input")
        return constructComponent<Input>(name);
    if (component == "output")
        return constructComponent<Output>(name);
    for (const auto &constructor : COMPONENTS_CONSTRUCTORS) {
        if (constructor.first == component)
            return constructor.second(name);
    }
    return createCircuit(component, name);
}

template <typename T>
std::shared_ptr<nts::IComponent> nts::ComponentFactory::constructComponent(std::string name)
{
    return std::make_shared<T>(name);
}

std::shared_ptr<nts::IComponent> nts::ComponentFactory::createCircuit(const std::string &component, const std::string& name)
{
    return std::make_shared<nts::Circuit>(component + ".nts", name);
}
