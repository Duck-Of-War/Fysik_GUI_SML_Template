#include "MovingCircle.h"
#include <math.h>
#include <cmath>
void MovingCircle::init(int m,float vx, float vy, bool color)
{
    Velocity = sf::Vector2f(vx,vy);
    mass = m;
    Size = mass/mdiv;
    Circle.setRadius(Size);
    c = color;
}

void MovingCircle::Update(sf::RenderWindow & WIN,sf::Shape & Static)
{
    GetPosition();
    //The circle we want to accelerate towards.
    StaticPos = Static.getPosition();
	Render(WIN);
    //If we know the acceleration, moving with velocity every frame and changing velocity according to acceleration is how it works.
	Circle.move(Velocity);
	Velocity += Acceleration;

    //The math for figuring out acceleration:

    //the pythagorean theorem, for figuring out the vector/distance between the movingcircle and the staticcircle
    a2 = pow(fabs(StaticPos.x - Position.x), 2);
    b2 = pow(fabs(StaticPos.y - Position.y), 2);
    FDistance = sqrt(a2 + b2);

    //there is probably a smoother way to do this, but:
    //since the FDistance can only be positive, the object would only accelerate one way.
    //I check which side of the staticcircle the movingcircle is on, and set the direction of the acceleration accordingly.
    Distance.y = StaticPos.y - Position.y;
    Distance.x = StaticPos.x - Position.x;
    //the formula that gives the acceleration is based on the Universal Law of Gravitation.
    if (Distance.x >= 0)
    {
        Acceleration.x = mass / pow(FDistance, 2);

    }
    else
    {
        Acceleration.x = mass / pow(FDistance, 2) * -1;

    }
    if (Distance.y >= 0)
    {
        Acceleration.y = mass / pow(FDistance, 2);

    }
    else
    {
        Acceleration.y = mass / pow(FDistance, 2) * -1;

    }
    // updates the colour so the circle changes colour depending on how it moves in which direction.
    if (c == true)
    {
        velf = ((fabs(Velocity.x) + fabs(Velocity.y)) / 2) * 70;
        vely = fabs(Velocity.y) * 70;
        velx = fabs(Velocity.x) * 70;
        if (velx >= 255)
        {
            velx = 255;
        }
        if (vely >= 255)
        {
            vely = 255;
        }
        if (velf >= 255)
        {
            velf = 255;
        }

        Circle.setFillColor(sf::Color(velf, velx, vely));
    }
}

MovingCircle::MovingCircle(int m, float vx, float vy, bool color)
{
	init(m,vx,vy, color);
}
