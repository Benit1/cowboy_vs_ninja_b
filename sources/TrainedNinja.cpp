//
// Created by beni on 5/15/23.
//
#include "TrainedNinja.hpp"

namespace ariel {
//constructors:
    TrainedNinja::TrainedNinja(std::string name, Point pos) : Ninja(std::move(name), pos, TrainedNinja_life,
                                                                    TrainedNinja_speed) {

    }
}