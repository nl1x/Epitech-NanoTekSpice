/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Xor.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef XOR_HPP
    #define XOR_HPP
    #include "Components/Abstract/AComponent.hpp"

namespace nts
{

    class Xor final : public AComponent
    {
        public:
            explicit Xor(const std::string &name);
            void compute() override;
    };

}

#endif //XOR_HPP
