//
// Created by beni on 5/15/23.
//
#include "Cowboy.hpp"

#include <utility>
#include <sstream>

namespace ariel {
    Cowboy::Cowboy(std::string name, Point pos) : Character(pos, life, std::move(name)) {

    }

    void ariel::Cowboy::shoot(Character *enemy) {

    }

    bool Cowboy::hasbullets() const {
        return false;
    }

    void Cowboy::reload() {

    }

    std::string Cowboy::print() const {
        std::ostringstream cowboyStream;
        cowboyStream << "C: ";

        if (getLife() > 0) {
            cowboyStream << getName() << " HP:" << getLife() << " Position:" << getPosition().print();
        } else {
            cowboyStream << "(" << getName() << ") Position:" << getPosition().print();
        }

        return cowboyStream.str();
    }

}