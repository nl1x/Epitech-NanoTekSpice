/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Clock.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef CLOCK_HPP
    #define CLOCK_HPP
    #include "Components/Abstract/AComponent.hpp"

namespace nts
{

    class Clock final : public AComponent
    {
        public:
            explicit Clock(const std::string &name);
            void update();
            void compute() override;
    };

}

#endif //CLOCK_HPP
