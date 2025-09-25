//
// Created by elies on 3/9/25.
//

#ifndef FLIPFLOP_HPP
#define FLIPFLOP_HPP
#include <string>

#include "Abstract/AComponent.hpp"

namespace nts {
    class Flipflop : public AComponent {
    public:
        explicit Flipflop(const std::string &name);
        void compute() override;
    private:
        bool _state = false;
        bool _lastClk = false;
    };
}


#endif //FLIPFLOP_HPP
