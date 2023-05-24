//
// Created by beni on 5/15/23.
//
#include <stdexcept>
#include "Character.hpp"

namespace ariel {
//constructors:
    Character::Character(Point pos, int life, std::string name) : position(pos), life_points(life), name(name) {

    }

//copy constructor
    Character::Character(Character &character) : position(character.position), life_points(character.life_points),
                                                 name(character.name) {

    }

//move constructor
    Character::Character(Character &&character) noexcept: position(character.position),
                                                          life_points(character.life_points), name(character.name) {

    }

//destructor
    Character::~Character() {

    }



//functions:
//return true if the character life points is bigger than 0
    bool ariel::Character::isAlive() const {
        if (this->life_points > 0) {
            return true;
        }
        return false;
    }

//receives a pointer to another character and returns the distance between the characters
    double Character::distance(Character *other) {
        return this->position.distance(other->position);
    }

    void Character::hit(int damage) {
        if (damage < 0) throw std::invalid_argument("Damage can't be negative number");
        this->life_points -= damage;
        //life points cant be negative
        if (this->life_points < 0) {
            life_points = 0;
        }
    }


    std::string Character::getName() const {
        return this->name;
    }

    Point Character::getLocation() const {
        return this->position;
    }

    void Character::setLocation(const Point &pos) {
        Character::position = pos;
    }

    int Character::getLife() const {
        return this->life_points;
    }

    //return true if Character is in team
    bool Character::getInTeam() const {
        return this->in_team;
    }

    //set Character in team
    void Character::setInTeam() {
        this->in_team = true;
    }

    void Character::setLeader() {
        this->leader = true;
    }

    void Character::removeLeader() {
        this->leader = false;
    }

    Character& Character::operator=(const Character& character){
        return (*this);
    }


    Character &Character::operator=(Character &&character) noexcept {
        return (*this);
    }


}