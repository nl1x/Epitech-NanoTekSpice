/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** ComponentAnd.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef COMPONENTAND_HPP
    #define COMPONENTAND_HPP
    #include "Components/Abstract/AComponent.hpp"

namespace nts
{

    class And final : public AComponent
    {
        public:
            explicit And(const std::string &name);
            void compute() override;
    };

}

#endif //COMPONENTAND_HPP
