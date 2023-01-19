#pragma once
#include "Object.h"
#include <TGUI/TGUI.hpp>

class CircleObject:
    public Object
{
    public:
    int Size = 50;
    bool is_red = false;
    void init();
   // sf::CircleShape  = Circle(Size);
    CircleObject();
    CircleObject(sf::CircleShape Circle);
};

