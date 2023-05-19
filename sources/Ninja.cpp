//
// Created by beni on 5/15/23.
//
#include "Ninja.hpp"

#include <utility>

namespace ariel {
//constructors:
    Ninja::Ninja(std::string name, Point pos, int life, int speed) : Character(pos, life, std::move(name)),
                                                                     speed(speed) {
    }

    Ninja::Ninja(Ninja &ninja) : Character(ninja) {
    }

    Ninja::Ninja(Ninja &&ninja) noexcept: Character(ninja) {
    }

//functions:
    void ariel::Ninja::move(Character *enemy) {

    }

    void Ninja::slash(Character *enemy) {

    }

    int Ninja::getSpeed() const {
        return 0;
    }


}