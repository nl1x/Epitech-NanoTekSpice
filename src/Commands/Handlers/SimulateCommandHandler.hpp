//
// Created by elies on 2/28/25.
//

#ifndef SIMULATECOMMANDHANDLER_HPP
    #define SIMULATECOMMANDHANDLER_HPP
    #include "Core/Core.hpp"
    #include "Commands/Handlers/ICommandHandler.hpp"
    #include <memory>

namespace nts {

    class SimulateCommandHandler : public ICommandHandler
    {
        public:
            explicit SimulateCommandHandler(nts::Core &core) : ICommandHandler(), core_(core) {};
            void resetChecks() const;
            // void computeOutputs();
            bool execute(CommandProcessor &processor, const std::string &commandLine);
            void computeAllComponents();
            void computeAllOutputs() const;

        private:
            Core &core_;
    };

}


#endif //SIMULATECOMMANDHANDLER_HPP
