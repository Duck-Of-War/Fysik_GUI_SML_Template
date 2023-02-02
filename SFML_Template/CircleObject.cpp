#include "CircleObject.h"

sf::Shape* CircleObject::get_shape()
{
	CircleP = &Circle;
	return CircleP;
}

void CircleObject::init()
{
	get_shape();
	CircleP->setRadius(Size);
	
	m_Base = &Circle;
	if (is_red == true)
	{
		CircleP->setFillColor(sf::Color(155,0,0));

	}
	else
	{
		CircleP->setFillColor(sf::Color(0,0,155));
	}

}

CircleObject::CircleObject()
{
	init();
}
