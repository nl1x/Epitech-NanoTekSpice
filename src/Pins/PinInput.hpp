/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** PinInput.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef PININPUT_HPP
    #define PININPUT_HPP
    #include <memory>
    #include "Pins/Abstract/APin.hpp"
    #include "Pins/PinOutput.hpp"

namespace nts
{
    class PinInput final : public APin
    {
        public:
            explicit PinInput(IComponent &component);
            void link(std::shared_ptr<IPin> pin) override;
            std::shared_ptr<nts::IPin> getLink(size_t pin) override;
            std::shared_ptr<PinOutput> getLink() { return link_.lock() ;}
            size_t nbLinks() override;
        private:
            std::weak_ptr<PinOutput> link_;
    };

}

#endif //PININPUT_HPP
