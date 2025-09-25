/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** IError.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef IERROR_HPP
    #define IERROR_HPP
    #include <utility>

#include "Core/Parser.hpp"

namespace nts
{

    class Error : public std::exception
    {
        public:
            explicit Error(std::string msg) noexcept : _msg(std::move(msg)) {};
            [[nodiscard]] const char *what() const noexcept override { return this->_msg.data(); }
        private:
            std::string _msg;
    };

    class RuntimeError final : public Error
    {
        public:
            explicit RuntimeError(const std::string &msg) noexcept : Error(msg) {};
    };

    class ParserError : public Error
    {
        public:
            explicit ParserError(std::string msg) noexcept : Error(std::move(msg)) {};
            explicit ParserError(std::string error, const std::string &filename, const std::string &line, const int lineNb) noexcept : Error(
                "Invalid syntax at line n°" + nts::Parser::toString(lineNb) + " in file '" + filename + "':\n"
                + "\tDetail: " + std::move(error) + "\n"
                + "\tLine: '" + line + "'"
            ) {};
    };

    class FileError final : public ParserError
    {
        public:
            explicit FileError(std::string msg) noexcept : ParserError(std::move(msg)) {};
    };

    class ParseLineError final : public ParserError
    {
        public:
            explicit ParseLineError(const std::string &error, const std::string &filename, const std::string &line, const int lineNb) noexcept :
                ParserError(error, filename, line, lineNb) {};
    };

    class ComponentTypeError final : public ParserError
    {
        public:
            explicit ComponentTypeError(const std::string &error, const std::string &filename, const std::string &line, const int lineNb) noexcept :
                ParserError(error, filename, line, lineNb) {};
    };

    class OutOfBoundError final : public Error
    {
        public:
            explicit OutOfBoundError(const std::string &error) noexcept :
                Error(error) {};
    };

}

#endif //IERROR_HPP
