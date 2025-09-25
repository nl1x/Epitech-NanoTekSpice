//
// Created by elies on 2/28/25.
//

#ifndef DISPLAYCOMMANDHANDLER_HPP
    #define DISPLAYCOMMANDHANDLER_HPP
    #include "ICommandHandler.hpp"
    #include "Core/Core.hpp"
    #include <map>
    #include <memory>
    #include "../../Components/Output.hpp"
    #include "../../Components/Input.hpp"

class DisplayCommandHandler : public ICommandHandler {
private:
    nts::Core &core_;

    public:
        explicit DisplayCommandHandler(nts::Core &core) : ICommandHandler(), core_(core) {};

        bool execute(CommandProcessor &processor, const std::string &commandLine);

    private:
        char tristateToChar(nts::Tristate state) const;
};



#endif //DISPLAYCOMMANDHANDLER_HPP
