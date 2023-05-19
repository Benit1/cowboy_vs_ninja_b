//
// Created by beni on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_OLDNINJA_HPP
#define COWBOY_VS_NINJA_OLDNINJA_HPP



#include "Ninja.hpp"

namespace ariel {
    const int OldNinja_speed = 8;
    const int OldNinja_life = 150;

    class OldNinja : public Ninja {
    public:
//constructor:
        OldNinja(std::string name, Point pos);
    };
}
#endif