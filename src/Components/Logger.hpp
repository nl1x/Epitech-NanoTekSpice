/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Logger.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef LOGGER_HPP
    #define LOGGER_HPP
    #include "Components/Abstract/AComponent.hpp"

namespace nts
{

    class Logger final : public AComponent
    {
        public:
            explicit Logger(const std::string &name);
            void compute() override;
    };

}

#endif //LOGGER_HPP
