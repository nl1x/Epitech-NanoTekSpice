/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** PinOutput.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef PINOUTPUT_HPP
    #define PINOUTPUT_HPP
    #include <list>
    #include <memory>
    #include "Pins/Abstract/APin.hpp"

namespace nts
{
    class PinInput;

    class PinOutput final : public APin
    {
        public:
            explicit PinOutput(IComponent &component);
            void link(std::shared_ptr<IPin> pin) override;
            std::shared_ptr<nts::IPin> getLink(size_t pin) override;
            std::list<std::shared_ptr<PinInput>> getLinks() { return _links ;}
            size_t nbLinks() override;
        private:
            std::list<std::shared_ptr<PinInput>> _links;
    };

}

#endif //PINOUTPUT_HPP
