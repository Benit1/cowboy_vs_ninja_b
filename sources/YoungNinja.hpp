//
// Created by beni on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_YOUNGNINJA_HPP
#define COWBOY_VS_NINJA_YOUNGNINJA_HPP


#include "Ninja.hpp"

namespace ariel {
    const int YoungNinja_speed = 14;
    const int YoungNinja_life = 100;

    class YoungNinja : public Ninja {
    public:
//constructor:
        YoungNinja(std::string name, Point pos);
    };
}
#endif