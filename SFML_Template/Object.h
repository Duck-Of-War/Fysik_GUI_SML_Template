#pragma once
#include <TGUI/TGUI.hpp>
class Object
{
	//Abstracted root class for my physicsobjects.
public:
	sf::Vector2f Position;

	sf::Shape * m_Base;
	float mass = 0.0;
	float mdiv = 15;
	Object();
	void Render(sf::RenderWindow & WIN);
	void GetPosition();
	void SetPosition(sf::Vector2f & POS);
};

