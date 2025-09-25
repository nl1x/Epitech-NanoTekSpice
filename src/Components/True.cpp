//
// Created by elies on 3/5/25.
//

#include "True.hpp"
#include <iostream>

nts::TrueComponent::TrueComponent(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "true.nts", name)
{
    auto pin = this->AComponent::getPin(1);

    pin->setValue(Tristate::True);
}

void nts::TrueComponent::compute()
{}