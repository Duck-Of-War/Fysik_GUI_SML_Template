#pragma once
#include "Object.h"
#include <TGUI/TGUI.hpp>

class CircleObject :
    public Object
{
public:
    sf::Shape* get_shape();
    int Size = 50;
    bool is_red = false;
    void init();
    // sf::CircleShape  = Circle(Size);
    CircleObject();
    sf::CircleShape Circle;
    sf::CircleShape* CircleP;
};