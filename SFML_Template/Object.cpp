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

		m_Base->getPosition();
		return;

}

void Object::SetPosition()
{
	Position = m_Base->getPosition();
	return;
}
