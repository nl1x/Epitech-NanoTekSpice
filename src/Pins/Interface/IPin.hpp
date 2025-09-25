/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** IPin.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef IPIN_HPP
    #define IPIN_HPP
    #include <memory>
    #include "Components/Interface/IComponent.hpp"

namespace nts
{

    class IPin
    {

        public:
            enum PinType { INPUT, OUTPUT, UNDEFINED };

            virtual ~IPin() = default;
            virtual void link(std::shared_ptr<IPin> pin) = 0; // Lier un pin à un autre
            virtual IComponent &getComponent() = 0; // Récupérer le component pour le compute afin d'obtenir sa valeur
            virtual std::shared_ptr<nts::IPin> getLink(size_t pin) = 0; // Récupérer le component pour le compute afin d'obtenir sa valeur
            virtual size_t nbLinks() = 0;
            virtual nts::Tristate getValue() = 0; // récupérer la valeur du pin (0, 1, U)
            virtual PinType getType() = 0;
            virtual void setValue(Tristate value) = 0;

    };

}

#endif //IPIN_HPP
