/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Input.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include "Components/Input.hpp"

nts::Input::Input(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "input.nts", name)
{}

void nts::Input::compute()
{
}
