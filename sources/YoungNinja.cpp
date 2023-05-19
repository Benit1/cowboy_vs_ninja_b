//
// Created by beni on 5/15/23.
//
#include "YoungNinja.hpp"

namespace ariel {
//constructors:
    YoungNinja::YoungNinja(std::string name, Point pos) : Ninja(std::move(name), pos, YoungNinja_life,
                                                                YoungNinja_speed) {

    }

}