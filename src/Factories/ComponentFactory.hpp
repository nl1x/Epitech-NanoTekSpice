/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** ComponentFactory.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef COMPONENTFACTORY_HPP
    #define COMPONENTFACTORY_HPP
    #include <functional>
    #include "Components/Interface/IComponent.hpp"
    #include "Components/And.hpp"
    #include "Components/Buffer.hpp"
    #include "Components/Circuit.hpp"
    #include "Components/Clock.hpp"
    #include "Components/Input.hpp"
    #include "Components/Not.hpp"
    #include "Components/Or.hpp"
    #include "Components/Output.hpp"
    #include "Components/Xor.hpp"
    #include "Components/Nor.hpp"
    #include "Components/Nand.hpp"
    #include "Components/True.hpp"
    #include "Components/False.hpp"
    #include "Components/TriState.hpp"
    #include "Components/Logger.hpp"
    #include <unordered_map>
    #include "Components/Flipflop.hpp"

namespace nts
{
    typedef std::shared_ptr<nts::IComponent>(*IComponentConstructor)(const std::string &name);

    class ComponentFactory
    {
    public:
        static std::shared_ptr<nts::IComponent> createComponent(const std::string& component, const std::string& name);

        template <typename T>
        static std::shared_ptr<IComponent> constructComponent(std::string name);
    private:
        static std::shared_ptr<nts::IComponent> createCircuit(const std::string &component, const std::string &name);
    };

    const std::unordered_map<std::string, std::function<std::shared_ptr<IComponent>(std::string)>> COMPONENTS_CONSTRUCTORS({
        { "and", ComponentFactory::constructComponent<And> },
        { "nand", ComponentFactory::constructComponent<Nand> },
        { "buffer", ComponentFactory::constructComponent<Buffer> },
        { "clock", ComponentFactory::constructComponent<Clock> },
        { "false", ComponentFactory::constructComponent<FalseComponent> },
        { "true", ComponentFactory::constructComponent<TrueComponent> },
        { "tristate", ComponentFactory::constructComponent<TriState> },
        { "input", ComponentFactory::constructComponent<Input> },
        { "not", ComponentFactory::constructComponent<Not> },
        { "or", ComponentFactory::constructComponent<Or> },
        { "nor", ComponentFactory::constructComponent<Nor> },
        { "output", ComponentFactory::constructComponent<Output> },
        { "xor", ComponentFactory::constructComponent<Xor> },
        { "logger", ComponentFactory::constructComponent<Logger> },
        {"flipflop", ComponentFactory::constructComponent<Flipflop>}
    });

}

#endif //COMPONENTFACTORY_HPP
