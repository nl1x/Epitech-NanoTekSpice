/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Input.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef INPUT_HPP
    #define INPUT_HPP
    #include "Components/Abstract/AComponent.hpp"

namespace nts
{

    class Input final : public AComponent
    {
    public:
        explicit Input(const std::string &name);
        void compute() override;
    };

}

#endif //INPUT_HPP
