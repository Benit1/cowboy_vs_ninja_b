//
// Created by beni on 5/15/23.
//
#include "Team.hpp"
#include <stdexcept>
#include <iostream>
#include <climits>

namespace ariel {
//constructors:
    ariel::Team::Team(Character *leader) {
        if (leader == nullptr) {
            throw std::invalid_argument("Leader is null");
        }
        if (leader->getInTeam())throw std::runtime_error("this Leader is already in a team");
        if (leader->getLife() == 0)throw std::runtime_error("Leader is dead ☠");
        this->leader = leader;
        team_size = 0;
        add(this->leader);
    }

//copy constructor
//    Team::Team(const Team &other) : leader(new Character(*(other.leader))), team_size(0) {
//
//    }

//move copy constructor
    Team::Team(Team &&other) noexcept: leader(other.leader), team_size(0) { other.leader = nullptr; }

//destructor
    Team::~Team() {
        for (size_t i = 0; i < max_team_members; i++) {
            delete team.at(i);
        }
    }


//functions:

//adding character to a team
    void Team::add(Character *new_team_member) {
        if (new_team_member == nullptr) throw std::invalid_argument("New member is null");
        if (new_team_member->getInTeam())throw std::runtime_error("New member is already in team");
        if (!new_team_member->isAlive()) throw std::invalid_argument("Cannot add dead member to the team");
        if (this->team_size == max_team_members) throw std::runtime_error("The team is full");
        new_team_member->setInTeam();
        Cowboy *C = dynamic_cast<Cowboy *>(new_team_member);
        Ninja *N = dynamic_cast<Ninja *>(new_team_member);
        if (C != nullptr) // new_team_member is a Cowboy
        {
            team[cowboysNum++] = new_team_member;
        } else if (N != nullptr) // new_team_member is a Ninja
        {
            team[max_team_members - 1 - (team_size - cowboysNum)] = new_team_member;
        }

        team_size++;
    }

    void Team::attack(Team *enemy_team) {
        if (enemy_team == nullptr) throw std::invalid_argument("New member is null");
        if (this == enemy_team)throw std::invalid_argument("Dont kill yourself");
        if (enemy_team->stillAlive() == 0) throw std::runtime_error("Enemy team is dead ☠");
        if (this->stillAlive() == 0)throw std::runtime_error("Dead team ☠ cant attack");
        if (!leader->isAlive()) {
            findNewLeader();
        }
        //find the closest enemy team member to the leader
        Character *victim = findClosestCharacter(leader, enemy_team);
        if (!victim) return;
        // Cowboys attack first
        for (size_t i = 0; i < cowboysNum; i++) {
            if (team.at(i) == nullptr) {
                continue;
            }
            if (team.at(i)->isAlive()) {
                Cowboy *C = dynamic_cast<Cowboy *>(team.at(i));
                if (C->hasboolets()) {
                    C->shoot(victim);
                } else {
                    C->reload();
                }
                if (!victim->isAlive()) {
                    victim = findClosestCharacter(getLeader(), enemy_team);
                }
                if (victim == nullptr)
                    break;
            }
        }
        // Ninjas attack after cowboys attack
        size_t ninjasNum = team_size - cowboysNum;
        for (size_t i = 9; i > 9 - ninjasNum; i--) {
            if (team.at(i) == nullptr) {
                continue;
            }
            if (team.at(i)->isAlive()) {
                if (victim == nullptr)break;
                Ninja *N = dynamic_cast<Ninja *>((team.at(i)));
                if (N->distance(victim) <= 1) {
                    N->slash(victim);
                } else {
                    N->move(victim);
                }
                if (!victim->isAlive()) {
                    victim = findClosestCharacter(getLeader(), enemy_team);
                }
                if (victim == nullptr)
                    break;
            }

        }

    }

    //Function that count how many team members is still alive
    int Team::stillAlive() const {
        int alive_counter = 0;
        for (size_t i = 0; i < max_team_members; i++) {
            if (team.at(i) != nullptr && team.at(i)->isAlive()) {
                alive_counter++;
            }
        }
        return alive_counter;
    };

    void Team::print() {
        std::cout << "Team 1 members: " << std::endl;
        for (size_t i = 0; i < cowboysNum; i++) {
            if (team.at(i) == nullptr) {
                continue;
            }
            if (team.at(i) == leader)
                std::cout << "LEADER";
            //prints the cowboys first
            std::cout << team.at(i)->print() << std::endl;
        }
        size_t ninjasNum = team_size - cowboysNum;
        for (size_t i = 9; i > 9 - ninjasNum; i--) {
            if (team.at(i) == nullptr) {
                continue;
            }
            if (team.at(i) == leader)
                std::cout << "LEADER";
            //prints the ninjas after
            std::cout << team.at(i)->print() << std::endl;
        }

    }

    Character *Team::findClosestCharacter(Character *character, Team *targetTeam) const {
        if (character == nullptr) throw std::invalid_argument("Character is null");
        if (targetTeam == nullptr) throw std::invalid_argument("Target team is null");
        // Initialize the nearest character as null
        Character *nearestCharacter = nullptr;
        // Initialize the minimum distance as the maximum possible int
        double minDist = INT_MAX;

        for (size_t i = 0; i < max_team_members; ++i) {
            // Get the current character from the target team
            Character *currCharacter = targetTeam->team.at(i);
            if (currCharacter != nullptr && currCharacter->isAlive()) {
                // Calculate the distance between the reference character and the current character
                double currDist = character->distance(currCharacter);
                // If the current distance is less than the minimum distance found so far
                // Update the minimum distance and set the nearest character to the current character
                if (currDist < minDist) {
                    minDist = currDist;
                    nearestCharacter = currCharacter;
                }
            }
        }

        return nearestCharacter;
    }

    void Team::findNewLeader() {
        Character *newLeader = findClosestCharacter(leader, this);
        if (newLeader != nullptr) {
            leader->removeLeader();
            leader = newLeader;
            leader->setLeader();
        }
    }

    const std::array<Character *, max_team_members> &Team::getTeam() const {
        return team;
    }

    Character *Team::getLeader() const {
        return leader;
    }

    unsigned int Team::getTeamSize() const {
        return team_size;
    }

    size_t Team::getCowboysNum() const {
        return cowboysNum;
    }


}


