/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Output.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef OUTPUT_HPP
    #define OUTPUT_HPP
    #include "Components/Abstract/AComponent.hpp"

namespace nts
{

    class Output final : public AComponent
    {
        public:
            explicit Output(const std::string &name);
            void compute() override;
    };

}

#endif //OUTPUT_HPP
