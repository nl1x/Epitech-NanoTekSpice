/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** ComponentBuffer.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef COMPONENTBUFFER_HPP
    #define COMPONENTBUFFER_HPP
    #include "Components/Abstract/AComponent.hpp"

namespace nts
{

    class Buffer final : public AComponent
    {
        public:
            explicit Buffer(const std::string &name);
            void compute() override;
    };

}

#endif //COMPONENTBUFFER_HPP
