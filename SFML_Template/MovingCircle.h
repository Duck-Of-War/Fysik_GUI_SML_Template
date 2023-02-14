#pragma once
#include "CircleObject.h"
#include <math.h>
#include <cmath>
//the object that moves around and accelerates towards the static circle.
class MovingCircle :
    public CircleObject
{
public:
    //Variables
    sf::Vector2f Acceleration;
    sf::Vector2f Velocity;
    sf::Vector2f Distance;
    sf::Vector2f StaticPos;
    sf::Vector2f damn;
    float FDistance;
    float a2;
    float b2;
    
    // m is mass, vx is initial velocity in X-axis, vy is initial velocity in Y-axis.
    void init(int m, float vx, float vy);
    MovingCircle(int m, float vx, float vy);

    //Static is the object to accelerate towards.
    void Update(sf::RenderWindow & WIN,sf::Shape & Static);


};

