//
// Created by beni on 5/15/23.
//
#include "Cowboy.hpp"

#include <utility>
#include <sstream>

namespace ariel {
    //constructor:
    Cowboy::Cowboy(std::string name, Point pos) : Character(pos, life, std::move(name)), bullets(bullet_amount) {

    }

    int Cowboy::getBullets() const {
        return bullets;
    }

    void ariel::Cowboy::shoot(Character *enemy) {
        if (enemy == nullptr) {
            throw std::invalid_argument("Enemy is null");
        }
        if (!enemy->isAlive()) throw std::runtime_error("Enemy K.O ☠️️");
        if (!this->isAlive()) throw std::runtime_error("I'm a dead cowboy ☠");
        if (this == enemy) throw std::runtime_error("Dont kill yourself");
        if (this->bullets == 0) {
            reload();
        } else {
            enemy->hit(10);
            this->bullets--;
        }


    }

    bool Cowboy::hasboolets() const {
        if (bullets > 0) { return true; }
        return false;
    }

    void Cowboy::reload() {
        if (!this->isAlive()) throw std::runtime_error("I'm a dead cowboy ☠");
        this->bullets = bullet_amount;
    }

    std::string Cowboy::print() {
        std::ostringstream cowboyStream;
        cowboyStream << "C: ";

        if (getLife() > 0) {
            cowboyStream << getName() << " HP:" << getLife() << " Position:" << getLocation().print();
        } else {
            cowboyStream << "(" << getName() << ") Position:" << getLocation().print();
        }

        return cowboyStream.str();
    }

}