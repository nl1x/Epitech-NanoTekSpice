//
// Created by elies on 2/28/25.
//

#ifndef COMMANDPROCESSOR_HPP
    #define COMMANDPROCESSOR_HPP
    #include <memory>
    #include <string>
    #include <unordered_map>
    #include "Core/Core.hpp"
    #include "Commands/Handlers/ICommandHandler.hpp"

//class ICommandHandler;

class CommandProcessor {
private:
    std::unordered_map<std::string, std::unique_ptr<ICommandHandler>> handlers_;
    nts::Core &core_; // ref aux core, pas besoins de rajouter chauqe membre du core

public:
    explicit CommandProcessor(nts::Core &core);
    ~CommandProcessor() = default;

    bool processCommand(const std::string &commandLine);

    //void WaitingCommandPushBack(std::string &command);
    //void deleteWaitingCommandPopFront();


protected:
    void registerCommands();

};

#endif //COMMANDPROCESSOR_HPP
