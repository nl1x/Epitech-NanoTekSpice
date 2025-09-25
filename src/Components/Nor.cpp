//
// Created by elies on 3/6/25.
//

#include "Nor.hpp"

nts::Nor::Nor(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "nor.nts", name)
{}

void nts::Nor::compute() {
    this->updateInputPins();

    auto a = getPin(1)->getValue();
    auto b = getPin(2)->getValue();
    auto output = getPin(3);

    if (a == nts::True || b == nts::True) {
        output->setValue(nts::False);
    } else if (a == nts::Undefined || b == nts::Undefined) {
        output->setValue(nts::Undefined);
    } else {
        output->setValue(nts::True);
    }
}