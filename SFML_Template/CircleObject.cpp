#include "CircleObject.h"

void CircleObject::init()
{
	sf::CircleShape Circle(Size);
	if (is_red == true)
	{
		Circle.setFillColor(sf::Color(155,0,0));

	}
	else
	{
		Circle.setFillColor(sf::Color(0,0,155));
	}
}
