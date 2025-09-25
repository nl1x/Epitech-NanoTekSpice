//
// Created by elies on 2/28/25.
//

#ifndef ASSIGNCOMMANDHANDLER_HPP
#define ASSIGNCOMMANDHANDLER_HPP
#include "Core/Core.hpp"
#include "ICommandHandler.hpp"
#include <map>
#include <memory>
#include "../../Components/Output.hpp"
#include "../../Components/Input.hpp"


class AssignCommandHandler : public ICommandHandler {
private:
    nts::Core &core_;

    public:
        explicit AssignCommandHandler(nts::Core &core) : ICommandHandler(), core_(core) {};

        bool execute(CommandProcessor &processor, const std::string &commandLine);

    private:
        nts::Tristate parseValue(const std::string &value);

};



#endif //ASSIGNCOMMANDHANDLER_HPP
