#pragma once
#include "CircleObject.h"
#include <math.h>
#include <cmath>
class MovingCircle :
    public CircleObject
{
public:
    sf::Vector2f Acceleration;
    sf::Vector2f Velocity;
    sf::Vector2f Distance;
    sf::Vector2f StaticPos;
    float FDistance;
    float a2;
    float b2;

    void init(int m, float vx, float vy);
    void Update(sf::RenderWindow & WIN,sf::Shape & Static);
    MovingCircle(int m, float vx, float vy);
};

