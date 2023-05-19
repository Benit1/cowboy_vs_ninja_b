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

    public:
//constructors:
        Character(Point pos, int life, std::string name);

        Character(Character &character);

        Character(Character &&character) noexcept;

        virtual ~Character();

//functions:
        bool isAlive();

        double distance(Character *other);

        void hit(int damage);

        std::string getName();

        Point getPosition();

        int getLife();

        std::string print();
    };
}
#endif