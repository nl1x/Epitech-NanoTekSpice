//
// Created by elies on 3/6/25.
//

#ifndef NAND_HPP
    #define NAND_HPP
#include "Abstract/AComponent.hpp"

namespace nts
{

    class Nand final : public AComponent
    {
    public:
        explicit Nand(const std::string &name);
        void compute() override;
    };

}



#endif //NAND_HPP
