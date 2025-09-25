//
// Created by elies on 3/6/25.
//

#include "Nand.hpp"

#include <iostream>

nts::Nand::Nand(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "nand.nts", name)
{}

void nts::Nand::compute() {
    this->updateInputPins();

    auto a = getPin(1)->getValue();
    auto b = getPin(2)->getValue();
    auto output = getPin(3);

    if (a == False || b == False) {
        output->setValue(nts::True);
    } else if (a == nts::Undefined || b == nts::Undefined) {
        output->setValue(nts::Undefined);
    } else
        output->setValue(nts::False);
}