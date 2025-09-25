//
// Created by elies on 3/5/25.
//

#ifndef FALSE_HPP
    #define FALSE_HPP
    #include "Abstract/AComponent.hpp"

namespace nts
{

    class FalseComponent final : public AComponent
    {
    public:
        explicit FalseComponent(const std::string &name);
        void compute() override;
    };

}



#endif //FALSE_HPP
