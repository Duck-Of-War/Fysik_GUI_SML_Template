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
    //physics math floats
    float FDistance;
    float a2;
    float b2;
    //velocity color math variables
    float velf;
    float vely;
    float velx;
    bool c;
    // m is mass, vx is initial velocity in X-axis, vy is initial velocity in Y-axis, color is if the color changes depending on velocity.
    void init(int m, float vx, float vy, bool color);
    MovingCircle(int m, float vx, float vy,bool color);

    //Static is the object to accelerate towards.
    void Update(sf::RenderWindow & WIN,sf::Shape & Static);


};

