/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** AComponent.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef ACOMPONENT_HPP
    #define ACOMPONENT_HPP
    #include "Components/Interface/IComponent.hpp"
    #include "Pins/Interface/IPin.hpp"
    #include <vector>
    #include <map>

namespace nts
{

    class AComponent : public IComponent
    {
        public:
            explicit AComponent(std::string name);
            explicit AComponent(const std::string &filePath, const std::string &name);
            ~AComponent() override = default;

            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
            void updateInputPins() override;

            [[nodiscard]] std::shared_ptr<IPin> getPin(std::size_t pin) override;
            virtual void parseFile(const std::string& filePath); // est appelé dans le constructeur
            std::string getName() override;

            void check() override;
            bool isChecked() override;
            void resetCheck() override;

        protected:
            void createPins(const std::map<size_t, IPin::PinType>& pinsType);
            std::vector<std::shared_ptr<IPin>> getPins() override { return _pins ;}
            //virtual nts::Tristate computeOutput() = 0; //// méthode pour les composants basic (AND, OR, etc.)
            std::vector<std::shared_ptr<nts::IPin>> _pins;

        private:
            bool _isCheck;
            const std::string name_m;
    };


}

#endif //ACOMPONENT_HPP
