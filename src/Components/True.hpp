//
// Created by elies on 3/5/25.
//

#ifndef TRUE_HPP
    #define TRUE_HPP
    #include "Abstract/AComponent.hpp"

namespace nts
{

    class TrueComponent final : public AComponent
    {
        public:
            explicit TrueComponent(const std::string &name);
            void compute() override;
        };

}

#endif //TRUE_HPP
