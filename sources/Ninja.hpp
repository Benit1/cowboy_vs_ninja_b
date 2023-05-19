//
// Created by beni on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_NINJA_HPP
#define COWBOY_VS_NINJA_NINJA_HPP



#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {
    private:
        int speed;

    public:
//constructors:
        Ninja(std::string name, Point pos, int life, int speed);

        Ninja(Ninja &nin);

        Ninja(Ninja &&nin) noexcept;

//functions:
        void move(Character *enemy);

        void slash(Character *enemy);

        int getSpeed() const;
    };

}
#endif