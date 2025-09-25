/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** main.cpp
** Author: nathan.jeannot@epitech.eu
*/

#include <iostream>
#include "Core/Core.hpp"

int main(int ac, char **av)
{
    if (ac <= 1) {
        return ERROR;
    }

    const std::string filePath(av[1]);
    try {
        nts::Core core(filePath);
        core.run();
    } catch (const std::exception &err) {
        std::cerr << "[ERROR] " << err.what() << std::endl;
        return ERROR;
    }
    return 0;
}
