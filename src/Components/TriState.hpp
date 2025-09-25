/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** TriState.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef TRISTATE_HPP
    #define TRISTATE_HPP
    #include "Components/Abstract/AComponent.hpp"

namespace nts
{

    class TriState final : public AComponent
    {
        public:
            explicit TriState(const std::string &name);
            void compute() override;
    };

}


#endif //TRISTATE_HPP
