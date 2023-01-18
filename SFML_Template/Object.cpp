#include "Object.h"

void Object::init()
{
	float Mass;
}

Object::Object()
{
	init();
}

void Object::Render(sf::RenderWindow WIN, sf::CircleShape * Circle, sf::RectangleShape * RECT)
{

	if (Circle != 0)
	{
		WIN.draw(*Circle);
	}
	else if (RECT != 0)
	{
		WIN.draw(*RECT);
	}
	else
	{
		std::cout << "ERROR, SHAPE POINTERS IN OBJECT RENDER NULL"<<std::endl;
	}
}

void Object::GetPosition(sf::CircleShape* CIRC, sf::RectangleShape* RECT)
{
	if (CIRC != 0)
	{
		CIRC->getPosition();
		return;
	}
	else if (RECT != 0)
	{
		RECT->getPosition();
		return;
	}
	else
	{
		std::cout << "GET POSITION ERROR, SHAPE POINTERS NULL" << std::endl;
	}
}
