#pragma once
#include <TGUI/TGUI.hpp>

class Object
{
	//Abstracted root class for uuhhha lll
public:
	sf::Vector2f Position;
	float mass;
	void init();
	Object();
	void Render(sf::RenderWindow WIN, sf::CircleShape* CIRC, sf::RectangleShape* RECT);
	void GetPosition(sf::CircleShape* CIRC, sf::RectangleShape* RECT);
};

