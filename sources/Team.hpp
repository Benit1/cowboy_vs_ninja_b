//
// Created by beni on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_TEAM_HPP
#define COWBOY_VS_NINJA_TEAM_HPP



#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "array"

namespace ariel {
    int const team_members = 10;

    class Team {
    private:
        std::array<Character *, team_members> team;
    public:
//constructors:
        Team(Character *leader);

        Team(Team &tem);

        Team(Team &&tem) noexcept;

        ~Team();

//functions:
        void add(Character *new_team_member);

        void attack(Team *enemy_team);

        int stillAlive();

        void print();

    };
}
#endif