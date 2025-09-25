/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** ComponentCircuit.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef COMPONENTCIRCUIT_HPP
    #define COMPONENTCIRCUIT_HPP
    #include "Core/Parser.hpp"
    #include "Components/Buffer.hpp"
    #include "Components/Abstract/AComponent.hpp"
    #include <list>
    #include <map>

namespace nts
{

    class Circuit final : public AComponent
    {
        public:
            explicit Circuit(const std::string& filename, const std::string &name);
            void parseFile(const std::string &filePath) override;
            void compute() override;
            void createSelfPins(std::map<size_t, IPin::PinType> pins, std::map<size_t, nts::Parser::Link> selfPins);
            [[nodiscard]] std::shared_ptr<IComponent> getComponent(const std::string& name);
        private:
            std::list<Buffer> buffers_;
            std::map<std::string, std::shared_ptr<IComponent>> components_;
    };

}

#endif //COMPONENTCIRCUIT_HPP
