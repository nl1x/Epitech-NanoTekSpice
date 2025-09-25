//
// Created by elies on 3/6/25.
//

#ifndef NOR_HPP
    #define NOR_HPP
    #include "Abstract/AComponent.hpp"

namespace nts
{

    class Nor final : public AComponent
    {
    public:
        explicit Nor(const std::string &name);
        void compute() override;
    };

}



#endif //NOR_HPP
