#include "Object.h"

void Object::init()
{


}

Object::Object()
{
	init();
}

void Object::Render(sf::RenderWindow & WIN)
{
	WIN.draw(*m_Base);
}

void Object::GetPosition()
{

		Position = m_Base->getPosition();
		return;

}

void Object::SetPosition(sf::Vector2f &POS)
{
	m_Base->setPosition(POS);
	return;
}
