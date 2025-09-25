/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** IComponent.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef ICOMPONENT_HPP
    #define ICOMPONENT_HPP
    // #define COMPONENT_CONFIG_FOLDER std::string("config/")
    #include <string>
    #include <memory>
#include <vector>

const std::string COMPONENT_CONFIG_FOLDER("config/");
const std::string LOGGER_FILE_NAME("./log.bin");

namespace nts
{

    class IPin;

    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;
            virtual void compute() = 0; // calculer la valeur des pins OUTPUT en fonction des pins INPUT
            virtual void updateInputPins() = 0; // Update input pins
            virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
            virtual std::shared_ptr<IPin> getPin(std::size_t pin) = 0;
            virtual std::vector<std::shared_ptr<IPin>> getPins() = 0;
            virtual std::string getName() = 0;
            virtual bool isChecked() = 0;
            virtual void check() = 0;
            virtual void resetCheck() = 0;
    };

}

#endif //ICOMPONENT_HPP
