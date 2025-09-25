//
// Created by elies on 3/5/25.
//

#include "False.hpp"

nts::FalseComponent::FalseComponent(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "false.nts", name)
{
    auto pin = this->AComponent::getPin(1);

    pin->setValue(Tristate::False);
}

void nts::FalseComponent::compute()
{}
