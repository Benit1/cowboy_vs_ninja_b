//
// Created by beni on 5/15/23.
//

#include <stdexcept>
#include <climits>
#include "SmartTeam.hpp"


ariel::SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

void ariel::SmartTeam::attack(Team *enemy_team) {
    if (enemy_team == nullptr) throw std::invalid_argument("Enemy team is null");
    if (this == enemy_team)throw std::invalid_argument("Dont kill yourself");
    if (enemy_team->stillAlive() == 0) throw std::runtime_error("Enemy team is dead ☠");
    if (this->stillAlive() == 0)throw std::runtime_error("Dead team ☠ cant attack");
    //find new leader if needed
    if (!getLeader()->isAlive()) {
        findNewLeader();
    }
    //ninja's will first attack the closest enemy's
    size_t ninjasNum = getTeamSize() - getCowboysNum();
    for (size_t i = 9; i > 9 - ninjasNum; i--) {
        if (getTeam().at(i) == nullptr) {
            continue;
        }
        if (getTeam().at(i)->isAlive()) {
            Ninja *N = dynamic_cast<Ninja *>((getTeam().at(i)));
            Character *closestEnemy = findClosestCharacter(getTeam().at(i), enemy_team);
            if (N->distance(closestEnemy) <= 1) {
                N->slash(closestEnemy);
            } else {
                N->move(closestEnemy);
            }
        }
    }

// cowboy's with the highest number of bullets will first attack the enemy's with the lowest health
    Cowboy *cowboyWithMostBullets = findCowboyWithMostBullets();
    Character *weakestEnemy = findWeakestEnemy(enemy_team);
    // Check if the enemy is still alive after the attack
    if (!weakestEnemy->isAlive()) {
        // Find the next weakest enemy
        weakestEnemy = findWeakestEnemy(enemy_team);
    }
    if (cowboyWithMostBullets->hasboolets()) {
        cowboyWithMostBullets->shoot(weakestEnemy);
    }
    // Check if the enemy is still alive after the attack
    if (weakestEnemy == nullptr || !weakestEnemy->isAlive()) {
        return;
    }
}


ariel::Cowboy *ariel::SmartTeam::findCowboyWithMostBullets() {
    Cowboy *cowboyWithMostBullets = nullptr;
    int maxBullets = 0;

    for (size_t i = 0; i < getCowboysNum(); i++) {
        Cowboy *cowboy = dynamic_cast<Cowboy *>(getTeam().at(i));
        if (cowboy != nullptr && cowboy->hasboolets() && cowboy->getBullets() > maxBullets) {
            cowboyWithMostBullets = cowboy;
            maxBullets = cowboy->getBullets();
        }
    }

    return cowboyWithMostBullets;
}


ariel::Character *ariel::SmartTeam::findWeakestEnemy(Team *enemy_team) {
    Character *weakestEnemy = nullptr;
    int minHealth = INT_MAX;
    for (size_t i = 0; i < getTeamSize(); i++) {
        if (getTeam().at(i) && getTeam().at(i)->isAlive()) {
            int HP = enemy_team->getTeam().at(i)->getLife();
            if (HP < minHealth) {
                minHealth = HP;
                weakestEnemy = getTeam().at(i);
            }
        }
    }
    return weakestEnemy;
}


