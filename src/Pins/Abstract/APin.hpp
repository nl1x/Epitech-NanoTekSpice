/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** APin.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef APIN_HPP
    #define APIN_HPP
    #include "Pins/Interface/IPin.hpp"
    #include "Components/Interface/IComponent.hpp"
    #include "Error/Error.hpp"

namespace nts
{
    class APin : virtual public IPin
    {
        public:
            class InvalidPinTypeError final : public ParserError
            {
                public:
                    explicit InvalidPinTypeError(const std::string &msg): ParserError(msg) {};
            };

            explicit APin(IComponent &component, PinType type);
            ~APin() override = default;

            IComponent &getComponent() override; // Récupérer le component pour le compute afin d'obtenir sa valeur

            nts::Tristate getValue() override;
            PinType getType() override;
            void setValue(nts::Tristate value) override { value_ = value; };
        protected:
            const PinType type_m;
            nts::Tristate value_;
            IComponent &component_m;
    };

}

#endif //APIN_HPP
