/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** PinFactory.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef PINFACTORY_HPP
    #define PINFACTORY_HPP
    #include <memory>
    #include "Pins/Interface/IPin.hpp"

namespace nts
{

    class PinFactory
    {
        public:
            static std::shared_ptr<nts::IPin> createPin(IPin::PinType type, IComponent &component);
    };

}

#endif //PINFACTORY_HPP
