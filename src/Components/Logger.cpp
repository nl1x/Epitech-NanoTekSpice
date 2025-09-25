/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Logger.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Components/Logger.hpp"
#include "Error/Error.hpp"
#include <fstream>

nts::Logger::Logger(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "logger.nts", name)
{
    std::ofstream file(LOGGER_FILE_NAME, std::ios::app);
    file.close();
}

void nts::Logger::compute()
{
    this->updateInputPins();
    bool isOnePinUndefined = false;
    unsigned int i = 1;

    while (i <= 8 && !isOnePinUndefined) {
        const auto in = this->getPin(i)->getValue();
        isOnePinUndefined = (in == Undefined);
        i++;
    }

    if (isOnePinUndefined)
        return;
    
    const auto inhibit = this->getPin(10)->getValue();
    const auto clock = this->getPin(9)->getValue();
    const auto in1 = this->getPin(1)->getValue();
    const auto in2 = this->getPin(2)->getValue();
    const auto in3 = this->getPin(3)->getValue();
    const auto in4 = this->getPin(4)->getValue();
    const auto in5 = this->getPin(5)->getValue();
    const auto in6 = this->getPin(6)->getValue();
    const auto in7 = this->getPin(7)->getValue();
    const auto in8 = this->getPin(8)->getValue();
    std::ofstream file(LOGGER_FILE_NAME, std::ios::app);

    if (!file.is_open())
        throw FileError("Cannot open file '" + LOGGER_FILE_NAME + "'.");

    if (inhibit == False && clock == True) {
        unsigned char data = 0;

        data |= (in1 << 0);
        data |= (in2 << 1);
        data |= (in3 << 2);
        data |= (in4 << 3);
        data |= (in5 << 4);
        data |= (in6 << 5);
        data |= (in7 << 6);
        data |= (in8 << 7);
        file << data;
    }

    file.close();
}

