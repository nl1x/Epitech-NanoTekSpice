//
// Created by elies on 2/28/25.
//

#ifndef EXITCOMMANDHANDLER_HPP
#define EXITCOMMANDHANDLER_HPP
    #include "ICommandHandler.hpp"
    #include <map>
    #include <memory>
    #include "Core/Core.hpp"
    #include "../../Components/Input.hpp"


class ExitCommandHandler : public ICommandHandler {
private:
    nts::Core &core_;

    public:
        explicit ExitCommandHandler(nts::Core &core) : ICommandHandler(), core_(core) {};

        bool  execute(CommandProcessor &processor, const std::string &commandLine);
};



#endif //EXITCOMMANDHANDLER_HPP
