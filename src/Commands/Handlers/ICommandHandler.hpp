//
// Created by elies on 2/28/25.
//

#ifndef ICOMMANDHANDLER_HPP
    #define ICOMMANDHANDLER_HPP
    #include <string>

class CommandProcessor;

class ICommandHandler {
public:
    ICommandHandler() = default;
    virtual ~ICommandHandler() = default;

    virtual bool execute(CommandProcessor &processor, const std::string &commandLine) = 0;
};




#endif //ICOMMANDHANDLER_HPP
