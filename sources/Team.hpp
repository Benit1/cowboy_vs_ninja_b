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
        Character *leader;
        size_t team_size ;
        size_t cowboysNum = 0;
//        size_t ninjasNum = 0;

    public:
//constructors:
        explicit Team(Character *leader);

//        Team(const Team &other);

        Team(Team &&tem) noexcept;

        ~Team();

//functions:
        void add(Character *new_team_member);

        virtual void attack(Team *enemy_team);

        virtual void print();

        int stillAlive() const;

        Character *findClosestCharacter(Character *referenceCharacter, Team *targetTeam) const;

        void findNewLeader();

        const std::array<Character *, max_team_members> &getTeam() const;

        Character *getLeader() const;

        unsigned int getTeamSize() const;

        size_t getCowboysNum() const;



    };
}
#endif