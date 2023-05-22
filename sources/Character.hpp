//
// Created by beni on 5/15/23.
//

#include <string>
#include "Point.hpp"

#ifndef COWBOY_VS_NINJA_CHARACTER_H
#define COWBOY_VS_NINJA_CHARACTER_H


namespace ariel {
    class Character {
    private:
        Point position;
        int life_points;
        std::string name;
        bool in_team = false;
        bool leader = false;

    public:
//constructors:
        Character(Point pos, int life, std::string name);

        Character(Character &character);

        Character(Character &&character) noexcept;

        virtual ~Character();

//functions:
        bool isAlive() const;

        double distance(Character *other);

        void hit(int damage);

        std::string getName() const;

        Point getLocation() const;

        int getLife() const;

        void setLocation(const Point &position);

        bool getInTeam() const;

        void setInTeam();

        void setLeader();

        virtual std::string print() = 0;


        void removeLeader();
    };
}
#endif