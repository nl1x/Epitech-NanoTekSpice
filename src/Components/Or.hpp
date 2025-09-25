/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Or.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef OR_HPP
    #define OR_HPP
    #include "Components/Abstract/AComponent.hpp"

namespace nts
{

    class Or final : public AComponent
    {
        public:
            explicit Or(const std::string &name);

            //nts::Tristate computeOutput() override;

            void compute() override;
    };

}

#endif //OR_HPP
