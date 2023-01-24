#include "MovingCircle.h"
#include <math.h>
#include <cmath>
void MovingCircle::init(int m,float vx, float vy)
{
    Velocity = sf::Vector2f(vx,vy);
    mass = m;
    Size = mass/mdiv;
    Circle.setRadius(Size);
}

void MovingCircle::Update(sf::RenderWindow & WIN,sf::Shape & Static)
{
    GetPosition();
    StaticPos = Static.getPosition();
	Render(WIN);
	Circle.move(Velocity);
	Velocity += Acceleration;
    //The math:
    a2 = pow(fabs(StaticPos.x - Position.x), 2);
    b2 = pow(fabs(StaticPos.y - Position.y), 2);
    FDistance = sqrt(a2 + b2);

    Distance.y = StaticPos.y - Position.y;
    Distance.x = StaticPos.x - Position.x;
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
}

MovingCircle::MovingCircle(int m, float vx, float vy)
{
	init(m,vx,vy);
}
