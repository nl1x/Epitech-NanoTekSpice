//
// Created by elies on 3/9/25.
//

#include "Flipflop.hpp"

#include <iostream>
#include <string>

nts::Flipflop::Flipflop(const std::string &name):
    AComponent(COMPONENT_CONFIG_FOLDER + "flipflop.nts", name)
{
    AComponent::getPin(1)->setValue(nts::False);
    AComponent::getPin(2)->setValue(nts::True);
}

void nts::Flipflop::compute() {
    _lastClk = getPin(3)->getValue();
    this->updateInputPins();

    auto Q = getPin(1);
    auto nQ = getPin(2);
    auto clock = getPin(3)->getValue();
    auto reset = getPin(4)->getValue();
    auto data = getPin(5)->getValue();
    auto set = getPin(6)->getValue();

    if (set == nts::True && reset == nts::True) {
        _state = nts::True;
        Q->setValue(nts::True);
        nQ->setValue(nts::True);
        return;
    } else if (set == nts::True) {
        _state = nts::True;
    } else if (reset == nts::True) {
        _state = nts::False;
    } else if (clock == nts::True && _lastClk == nts::False) {
        _state = data == nts::True;
    }
    Q->setValue(_state ? nts::True : nts::False);
    nQ->setValue(_state ? nts::False : nts::True);
}
