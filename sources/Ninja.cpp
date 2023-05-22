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

    Ninja::Ninja(Ninja &&ninja) noexcept: Character(ninja), speed(ninja.speed) {
    }

    //destructor
    Ninja::~Ninja() {

    }

//functions:
    void ariel::Ninja::move(Character *enemy) {
        if (enemy == nullptr) {
            throw std::invalid_argument("Enemy is null");
        }
        if (!enemy->isAlive()) throw std::runtime_error("Enemy K.O ☠");
        if (!isAlive()) throw std::runtime_error("I'm a dead ninja ☠");
        Point src = this->getLocation();
        Point dest = enemy->getLocation();
        double distance = this->getSpeed();
        // Use the moveTowards function to get the new position
        Point newPosition = Point::moveTowards(src, dest, distance);
        // Update the Ninja's position
        this->setLocation(newPosition);
    }

    void Ninja::slash(Character *enemy) {
        if (enemy == nullptr) {
            throw std::invalid_argument("Enemy is null");
        }
        if (!enemy->isAlive()) throw std::runtime_error("Enemy K.O ☠️️");
        if (!this->isAlive()) throw std::runtime_error("I'm a dead ninja ☠");
        if (this == enemy) throw std::runtime_error("Dont kill yourself");
        if (this->distance(enemy) <= 1) {
            enemy->hit(40);
        }
    }

//return the ninja's speed
    int Ninja::getSpeed() const {
        return this->speed;
    }

    std::string Ninja::print()  {
        std::ostringstream ninjaStream;
        ninjaStream << "N: ";

        if (getLife() > 0) {
            ninjaStream << getName() << " HP:" << getLife() << " Position:" << getLocation().print();
        } else {
            ninjaStream << "(" << getName() << ") Position:" << getLocation().print();
        }

        return ninjaStream.str();
    }


}