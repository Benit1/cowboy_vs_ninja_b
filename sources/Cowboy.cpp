//
// Created by beni on 5/15/23.
//
#include "Cowboy.hpp"

#include <utility>

namespace ariel {
    void ariel::Cowboy::shoot(Character *enemy) {

    }

    bool Cowboy::hasbullets() const {
        return false;
    }

    void Cowboy::reload() {

    }

    Cowboy::Cowboy(std::string name, Point pos) : Character(pos, life, std::move(name)) {

    }

}