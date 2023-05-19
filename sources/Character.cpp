//
// Created by beni on 5/15/23.
//
#include "Character.hpp"

namespace ariel {
//constructors:
    Character::Character(Point pos, int life, std::string name) : position(pos), life_points(life), name(name) {

    }

    Character::Character(Character &character) : position(character.position) {

    }

    Character::Character(Character &&character) noexcept: position(character.position) {

    }

    Character::~Character() {

    }

//functions:
    bool ariel::Character::isAlive() {
        return false;
    }

    double Character::distance(Character *other) {
        return 0;
    }

    void Character::hit(int damage) {

    }

    std::string Character::getName() {
        return std::string();
    }

    Point Character::getPosition() {
        return Point(0, 0);
    }

    std::string Character::print() {
        return std::string();
    }

    int Character::getLife() {
        return 0;
    }


}