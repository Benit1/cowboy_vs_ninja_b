//
// Created by beni on 5/15/23.
//
#include "OldNinja.hpp"

namespace ariel {
//constructors:
    OldNinja::OldNinja(std::string name, Point pos) : Ninja(std::move(name), pos, OldNinja_life,
                                                            OldNinja_speed) {

    }

}