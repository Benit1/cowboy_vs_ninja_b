//
// Created by beni on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_TRAINEDNINJA_HPP
#define COWBOY_VS_NINJA_TRAINEDNINJA_HPP



#include "Ninja.hpp"

namespace ariel {
    const int TrainedNinja_speed = 12;
    const int TrainedNinja_life = 120;

    class TrainedNinja : public Ninja {
    public:
//constructor:
        TrainedNinja(std::string name, Point pos);
    };
}
#endif