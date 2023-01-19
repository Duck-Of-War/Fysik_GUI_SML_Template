#pragma once
#include <TGUI/TGUI.hpp>
// trying to understand dynamic cast, for casting a shape into either a rectangle or circle to render and so on
class Object
{
	//Abstracted root class for uuhhha lll
public:
	sf::Vector2f Position;

	sf::Shape *m_Base;
	sf::Shape *m_BaseP;
	float mass = 0.0;
	void init();
	Object();
	void Render(sf::RenderWindow & WIN);
	void GetPosition();
	void SetPosition();
};

