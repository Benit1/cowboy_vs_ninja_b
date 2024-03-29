//
// Created by beni on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_SMARTTEAM_HPP
#define COWBOY_VS_NINJA_SMARTTEAM_HPP


#include "Team.hpp"

namespace ariel {
    class SmartTeam : public Team {
    public:
        explicit SmartTeam(Character *leader);

        void attack(Team *enemy_team) override;

        Character *findWeakestEnemy(Team *otherTeam);

        Cowboy *findCowboyWithMostBullets();
    };
}
#endif