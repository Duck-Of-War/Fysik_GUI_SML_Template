#include "CircleObject.h"

void CircleObject::init()
{
	Circle.setRadius(Size);
	
	m_Base = &Circle;
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
