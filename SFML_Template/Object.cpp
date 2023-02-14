#include "Object.h"



Object::Object()
{
	//m_Base = get_shape();
}

//Renders the object in an sfml renderwindow
void Object::Render(sf::RenderWindow & WIN)
{
	WIN.draw(Circle);
}

//Sets Position to the object's shape's getPosition();
void Object::GetPosition()
{
		Position = Circle.getPosition();
		return;
}

//Sets the object's position.
void Object::SetPosition(sf::Vector2f &POS)
{
	Circle.setPosition(POS);
	return;
}
