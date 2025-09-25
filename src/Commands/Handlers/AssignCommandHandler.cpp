//
// Created by elies on 2/28/25.
//

#include "AssignCommandHandler.hpp"
#include "Error/Error.hpp"
#include <regex>

nts::Tristate AssignCommandHandler::parseValue(const std::string &value) {
    if (value == "0") return nts::Tristate::False;
    if (value == "1") return nts::Tristate::True;
    if (value == "U") return nts::Tristate::Undefined;
    throw std::invalid_argument("Invalid value: " + value);
}

bool AssignCommandHandler::execute(CommandProcessor &processor, const std::string &commandLine) {
    (void)processor;

    std::regex assignRegex(R"((\w+)=(0|1|U))");
    std::smatch match;

    if (!std::regex_match(commandLine, match, assignRegex))
        throw nts::RuntimeError("Invalid assignation format. Use: input=value (0, 1, U)");

    std::string inputName = match[1];
    std::string value = match[2];

    // Rajouter les Clocks
    if (core_.getIns().find(inputName) == core_.getIns().end() && core_.getClocks().find(inputName) == core_.getClocks().end())
        throw nts::RuntimeError("Unknown input: " + inputName);

    core_.addCommand(inputName.data(), parseValue(value));
    // std::cout << "Assignation stored: " << inputName << " = " << value << std::endl;

    return true;
}
