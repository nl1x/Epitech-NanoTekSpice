/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** ComponentBuffer.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Components/Buffer.hpp"
#include <iostream>

nts::Buffer::Buffer(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "buffer.nts", name)
{}

void nts::Buffer::compute()
{
    this->updateInputPins();

    auto in = this->getPin(1);
    auto out = this->getPin(2);

    out->setValue(in->getValue());
}
