/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Parser.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef PARSER_HPP
    #define PARSER_HPP
    #include <memory>
    #include <string>
    #include <map>
    #include "Components/Logger.hpp"
    #include "Pins/Interface/IPin.hpp"
    #include "Components/Interface/IComponent.hpp"

namespace nts
{
    class Input;
    class Output;
    class Clock;

    class Parser
    {
        enum Part
        {
            CHIPSETS = 10,
            LINKS = 7,
            PINS = 6,
            UNDEFINED = -1
        };

        public:
            class Link
            {
                public:
                    Link();
                    explicit Link(const std::string &data);
                    Link &operator=(const Link &rhs);
                    [[nodiscard]] std::string getName() const;
                    [[nodiscard]] size_t getPinID() const;
                private:
                    std::string name_;
                    size_t pinID_;
            };

            Parser();
            explicit Parser(const std::string &filePath);
            ~Parser() = default;

            [[nodiscard]] std::map<std::string, std::shared_ptr<IComponent>> getComponents() const;
            [[nodiscard]] std::map<std::string, std::shared_ptr<Input>> getInputs() const;
            [[nodiscard]] std::map<std::string, std::shared_ptr<Output>> getOutputs() const;
            [[nodiscard]] std::map<std::string, std::shared_ptr<Clock>> getClocks() const;
            [[nodiscard]] std::map<std::string, std::shared_ptr<Logger>> getLoggers() const;
            [[nodiscard]] std::map<size_t, IPin::PinType> getPins() const;
            [[nodiscard]] std::map<size_t, Link> getSelfPins() const;
            [[nodiscard]] std::string getFilename() const;

            static bool startsWith(const std::string &line, const std::string &start);
            static bool containsOnly(const std::string &line, const std::string &accepted, size_t offset);
            static void removeComments(std::string &line);

            static bool isNumber(const std::string &line);

            static std::string toString(size_t n);
            static size_t toLLInt(const std::string& str);
        private:
            bool setPart(const std::string &line);
            void handleChipsets(const std::string &line, int lineNb);
            void handleLinks(const std::string &line, int lineNb);
            void handlePins(const std::string &line, int lineNb);
            void handleSelfPins(const std::string &data, const std::string &line, int lineNb);
            void handleHeader(const std::string &line, int lineNb);

            Part part_;
            std::string filename_;
            std::map<std::string, std::shared_ptr<IComponent>> chipsets_;
            std::map<std::string, std::shared_ptr<IComponent>> components_;
            std::map<std::string, std::shared_ptr<Input>> inputs_;
            std::map<std::string, std::shared_ptr<Output>> outputs_;
            std::map<std::string, std::shared_ptr<Logger>> loggers_;
            std::map<std::string, std::shared_ptr<Clock>> clocks_;
            std::map<size_t, IPin::PinType> pins_;
            std::map<size_t, Link> selfPins_;
    };

}

#endif //PARSER_HPP
