//
// Created by beni on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_TEAM2_HPP
#define COWBOY_VS_NINJA_TEAM2_HPP


#include "Team.hpp"

namespace ariel {
    class Team2 : public Team {
    public:
        explicit Team2(Character *leader);

        void print() override;

        void attack(Team *enemy_team) override;
    };
}
#endif