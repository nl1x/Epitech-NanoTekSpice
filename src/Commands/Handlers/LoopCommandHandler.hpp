//
// Created by elies on 2/28/25.
//

#ifndef LOOPCOMMANDHANDLER_HPP
#define LOOPCOMMANDHANDLER_HPP
#include <map>
#include <memory>
#include <string>
#include <Components/Input.hpp>
#include <Components/Output.hpp>

#include "ICommandHandler.hpp"


class LoopCommandHandler : public ICommandHandler {
    private:
        nts::Core &core_;
    public:
        static void handleSignal(int signum);
        explicit LoopCommandHandler(nts::Core &core) : ICommandHandler(), core_(core) {};
        bool execute(CommandProcessor &processor, const std::string &commandLine);
};



#endif //LOOPCOMMANDHANDLER_HPP
