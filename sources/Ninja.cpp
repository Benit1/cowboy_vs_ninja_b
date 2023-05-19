//
// Created by beni on 5/15/23.
//
#include "Ninja.hpp"

#include <utility>
#include <sstream>

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

    std::string Ninja::print() const {
        std::ostringstream ninjaStream;
        ninjaStream << "N: ";

        if (getLife() > 0) {
            ninjaStream << getName() << " HP:" << getLife() << " Position:" << getPosition().print();
        } else {
            ninjaStream << "(" << getName() << ") Position:" << getPosition().print();
        }

        return ninjaStream.str();
    }


}