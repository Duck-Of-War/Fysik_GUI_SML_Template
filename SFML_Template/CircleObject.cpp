#include "CircleObject.h"

void CircleObject::init()
{
	sf::CircleShape Circle(Size);
	Circle.setPosition(Position.x,Position.y);
	if (is_red == true)
	{
		Circle.setFillColor(sf::Color(155,0,0));

	}
	else
	{
		Circle.setFillColor(sf::Color(0,0,155));
	}
}

CircleObject::CircleObject()
{
	init();
}
