#include "Object.h"


sf::Shape* Object::get_shape()
{
	return Temprect;

}

Object::Object()
{
	m_Base = get_shape();
}

//Renders the object in an sfml renderwindow
void Object::Render(sf::RenderWindow & WIN)
{
	WIN.draw(*m_Base);
}

//Sets Position to the object's shape's getPosition();
void Object::GetPosition()
{
		Position = m_Base->getPosition();
		return;
}

//Sets the object's position.
void Object::SetPosition(sf::Vector2f &POS)
{
	m_Base->setPosition(POS);
	return;
}
