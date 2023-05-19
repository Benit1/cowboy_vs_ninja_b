//
// Created by beni on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_COWBOY_H
#define COWBOY_VS_NINJA_COWBOY_H



#include "Character.hpp"


namespace ariel {
    const int bullet_amount = 6;
    const int life = 110;

    class Cowboy : public Character {
    public:
//constructor:
        Cowboy(std::string name, Point pos);

//functions:
        void shoot(Character *enemy);

        bool hasbullets() const;

        void reload();

    };
}
#endif