#pragma once
#include <TGUI/TGUI.hpp>
// trying to understand dynamic cast, for casting a shape into either a rectangle or circle to render and so on
class Object
{
	//Abstracted root class for uuhhha lll
public:
	sf::Vector2f Position;

	sf::Shape * m_Base;
	float mass = 0.0;
	float mdiv = 15;
	void init();
	Object();
	void Render(sf::RenderWindow & WIN);
	void GetPosition();
	void SetPosition(sf::Vector2f & POS);
};

