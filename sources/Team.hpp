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
    int const max_team_members = 10;

    class Team {
    private:
        std::array<Character *, max_team_members> team{};
        Character *leader{};
        unsigned int team_size{};
        unsigned int cowboysNum = 0;
        unsigned int ninjasNum = max_team_members - 1 - (team_size - cowboysNum);
    public:
//constructors:
        explicit Team(Character *leader);

//        Team(const Team &other);

        Team(Team &&tem) noexcept;

        ~Team();

//functions:
        void add(Character *new_team_member);

        void attack(Team *enemy_team);

        void print();

        int stillAlive() const;

        Character *findClosestCharacter(Character *referenceCharacter, Team *targetTeam) const;

        void findNewLeader();
    };
}
#endif