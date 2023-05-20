//
// Created by beni on 5/15/23.
//
#include <stdexcept>
#include "Team.hpp"

namespace ariel {
//constructors:
    ariel::Team::Team(Character *leader) {
        if (leader == nullptr) {
            throw std::invalid_argument("Leader is null");
        }
        if (leader->getInTeam())throw std::runtime_error("this Leader is already in a team");
        if (leader->getLife() == 0)throw std::runtime_error("Leader is dead ☠");
        leader->setInTeam();
        this->leader = leader;
        team_size = 1;

    }

//copy constructor
    Team::Team(const Team &other) : leader(new Character(*(other.leader))), team_size(0) {

    }

    Team::Team(Team &&tem) noexcept {
    }

    Team::~Team() {

    }


//functions:
    void Team::add(Character *new_team_member) {

    }

    void Team::attack(Team *enemy_team) {

    }

    int Team::stillAlive() {
        return 0;
    }

    void Team::print() {

    }


}