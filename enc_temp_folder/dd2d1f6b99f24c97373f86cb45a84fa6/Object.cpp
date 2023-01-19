#include "Object.h"

void Object::init()
{


}

Object::Object()
{
	m_Base = m_BaseP;
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
	m_Base->getPosition();
	return;
}
