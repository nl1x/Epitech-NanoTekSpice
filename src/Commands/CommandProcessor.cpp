//
// Created by elies on 2/28/25.
//


#include <memory>
#include <string>
#include <unordered_map>
#include "CommandProcessor.hpp"
#include "Commands/Handlers/ICommandHandler.hpp"
#include "Commands/Handlers/DisplayCommandHandler.hpp"
#include "Commands/Handlers/LoopCommandHandler.hpp"
#include "Commands/Handlers/SimulateCommandHandler.hpp"
#include "Commands/Handlers/AssignCommandHandler.hpp"
#include "Commands/Handlers/ExitCommandHandler.hpp"
#include "Error/Error.hpp"


CommandProcessor::CommandProcessor(nts::Core &core) : core_(core) {
    registerCommands();
}


void CommandProcessor::registerCommands() {
    this->handlers_["display"] = std::make_unique<DisplayCommandHandler>(core_);
    this->handlers_["loop"] = std::make_unique<LoopCommandHandler>(core_);
    this->handlers_["simulate"] = std::make_unique<nts::SimulateCommandHandler>(core_);
    this->handlers_["assignation"] = std::make_unique<AssignCommandHandler>(core_);
    this->handlers_["exit"] = std::make_unique<ExitCommandHandler>(core_);
}

/* trois cas possible :
 * commande vide = on met un message et return true
 * commande inconnue = on met un message et return true
 * commande connue = on execute la commande et return true si on doit continuer, false sinon
*/
bool CommandProcessor::processCommand(const std::string &commandLine) {
    if (commandLine.empty()) {
        return true;
    }
    auto exec = handlers_.find(commandLine);
    if (exec == handlers_.end() && commandLine.find('=') != std::string::npos)
        exec = handlers_.find("assignation");
    if (exec == handlers_.end())
        throw nts::RuntimeError("Command not found");
    return exec->second->execute(*this, commandLine);
}

