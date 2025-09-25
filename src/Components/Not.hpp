/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Not.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef NOT_HPP
    #define NOT_HPP
    #include "Components/Abstract/AComponent.hpp"

namespace nts
{

    class Not final : public AComponent
    {
    public:
        explicit Not(const std::string &name);
        void compute() override;
    };

}

#endif //NOT_HPP
