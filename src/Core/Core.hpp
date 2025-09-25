/*
** EPITECH PROJECT, 2025
** NTS
** File description:
** Core.hpp
** Author: nathan.jeannot@epitech.eu
*/

#ifndef CORE_HPP
    #define CORE_HPP
    #define ERROR 84
    #include <map>
    #include <string>
    #include <queue>
    #include "Core/Parser.hpp"
    #include "Components/Output.hpp"
    #include "Components/Clock.hpp"
    #include "Components/Input.hpp"

namespace nts
{

    class Core
    {
        public:
            explicit Core(const std::string &filePath);
            ~Core();
            void run();

            // getters & setters
            std::queue<std::pair<std::string, Tristate>> getCommands() const { return waiting_commands_; }
            const std::map<std::string, std::shared_ptr<nts::Output>> &getOuts() const { return outs_; }
            const std::map<std::string, std::shared_ptr<nts::Logger>> &getLoggers() const { return loggers_; }
            const std::map<std::string, std::shared_ptr<nts::Input>> &getIns() const { return ins_; }
            const std::map<std::string, std::shared_ptr<nts::Clock>> &getClocks() const { return clocks_; }
            size_t getThicks() const { return thicks_; }
            std::map<std::string, std::shared_ptr<IComponent>> &getComponents() { return components_;}

            void incrementThicks() { thicks_++; }
            void addCommand(const std::pmr::string &name, Tristate state);
            void applyWaitingCommands();


        private:
            void retrieveParserData();
            const Parser parser_m;
            void parseFile(const std::string &filePath);

            std::map<std::string, std::shared_ptr<IComponent>> components_;

            std::queue<std::pair<std::string, Tristate>> waiting_commands_;
            std::map<std::string, std::shared_ptr<nts::Input>> ins_;
            std::map<std::string, std::shared_ptr<nts::Output>> outs_;
            std::map<std::string, std::shared_ptr<nts::Logger>> loggers_;
            std::map<std::string, std::shared_ptr<nts::Clock>> clocks_;
            size_t thicks_;

            // à voir si on ajoute les true & false components
    };

}

#endif //CORE_HPP
