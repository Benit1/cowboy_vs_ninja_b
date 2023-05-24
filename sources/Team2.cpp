//
// Created by beni on 5/15/23.
//
#include <stdexcept>
#include <iostream>
#include "Team2.hpp"

ariel::Team2::Team2(Character *leader) : Team(leader) {

}

//The same as team, but the order of the attack will be according to the order of addition without distinguishing cowboys or ninjas.
void ariel::Team2::attack(ariel::Team *enemy_team) {
    if (enemy_team == nullptr) throw std::invalid_argument("Enemy team is null");
    if (this == enemy_team)throw std::invalid_argument("Dont kill yourself");
    if (enemy_team->stillAlive() == 0) throw std::runtime_error("Enemy team is dead ☠");
    if (this->stillAlive() == 0)throw std::runtime_error("Dead team ☠ cant attack");
    if (!getLeader()->isAlive()) {
        findNewLeader();
    }
    //find the closest enemy team member to the leader
    Character *victim = findClosestCharacter(getLeader(), enemy_team);
    if (!victim) return;
    for (size_t i = 0; i < max_team_members; i++) {
        if (getTeam().at(i) == nullptr) {
            continue;
        }
        if (getTeam().at(i)->isAlive()) {
            auto *C = dynamic_cast<Cowboy *>(getTeam()[i]);
            auto *N = dynamic_cast<Ninja *>(getTeam()[i]);
            if (C != nullptr) {
                if (C->hasboolets()) {
                    C->shoot(victim);
                } else C->reload();
            } else if (N != nullptr) {
                if (N->distance(victim) <= 1) {
                    N->slash(victim);
                } else {
                    N->move(victim);
                }
            }
        }
        if (!victim->isAlive()) {
            victim = findClosestCharacter(getLeader(), enemy_team);
        }
        if (victim == nullptr)
            break;
    }

}

void ariel::Team2::print() {

    for (size_t i = 0; i < getCowboysNum(); i++) {
        if (getTeam().at(i) == getLeader())
            std::cout << "LEADER";
        //prints the cowboys first
        std::cout << getTeam().at(i)->print() << std::endl;
    }
    size_t NinjasNum = getTeamSize() - getCowboysNum();
    for (size_t i = 9; i > 9 - NinjasNum; i--) {
        if (getTeam().at(i) == getLeader())
            std::cout << "LEADER";
        //prints the ninjas after
        std::cout << getTeam().at(i)->print() << std::endl;
    }
}


