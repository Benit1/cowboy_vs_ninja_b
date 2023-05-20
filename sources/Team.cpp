//
// Created by beni on 5/15/23.
//
#include <stdexcept>
#include <climits>
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
//    Team::Team(const Team &other) : leader(new Character(*(other.leader))), team_size(0) {
//
//    }

//move copy constructor
    Team::Team(Team &&other) noexcept: leader(other.leader), team_size(0) { other.leader = nullptr; }

//destructor
    Team::~Team() {
        for (size_t i = 0; i < 10; i++) {
            delete team.at(i);
        }
    }


//functions:

//adding character to a team
    void Team::add(Character *new_team_member) {
        if (new_team_member == nullptr) throw std::invalid_argument("New member is null");
        if (new_team_member->getInTeam())throw std::runtime_error("New member is already in team");
        if (!new_team_member->isAlive()) throw std::invalid_argument("Cannot add dead member to the team");
        new_team_member->setInTeam();
        Cowboy *C = dynamic_cast<Cowboy *>(new_team_member);
        Ninja *N = dynamic_cast<Ninja *>(new_team_member);
        if (C != nullptr) // new_team_member is a Cowboy
        {
            team[cowboysNum++] = new_team_member;
        } else if (N != nullptr) // new_team_member is a Ninja
        {
            team[ninjasNum++] = new_team_member;
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
        // Cowboys attack first


    }

    //Function that count how many team members is still alive
    int Team::stillAlive() const {
        int alive_counter = 0;
        for (unsigned int i = 0; i < team_size; i++) {
            if (team[i] != nullptr && team[i]->isAlive()) {
                alive_counter++;
            }
        }
        return alive_counter;
    };

    void Team::print() {

    }

    Character *Team::findClosestCharacter(Character *character, Team *targetTeam) const {
        if (character == nullptr) throw std::invalid_argument("Character is null");
        if (targetTeam == nullptr) throw std::invalid_argument("Target team is null");
        if (targetTeam->stillAlive() == 0) {
            throw std::invalid_argument("Target team has no characters alive");
        }
        // Initialize the nearest character as null
        Character *nearestCharacter = nullptr;
        // Initialize the minimum distance as the maximum possible int
        int minDist = INT_MAX;

        for (unsigned int i = 0; i < team_size; ++i) {
            // Get the current character from the target team
            Character *currCharacter = targetTeam->team[i];

            if (currCharacter && currCharacter->isAlive()) {
                // Calculate the distance between the reference character and the current character
                int currDist = character->distance(currCharacter);
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
        leader = findClosestCharacter(leader, this);
        leader->setLeader();
    }


}