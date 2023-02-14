#include "CircleObject.h"


void CircleObject::init()
{
	Circle.setRadius(Size);
	Circle.setFillColor(sf::Color(207,199,136));

}

CircleObject::CircleObject()
{
	init();
}
