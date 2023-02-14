#pragma once
#include <TGUI/TGUI.hpp>
class Object
{
	//Abstracted root class for my physicsobjects.
public:

	sf::Vector2f Position;
	
	sf::CircleShape Circle;

//mass and what to divide it by for size
	float mass = 0.0;
	float mdiv = 15
		
		;
	Object();

	//Draws the shape in the sfml window
	void Render(sf::RenderWindow &WIN);

	//selfexplanatory
	void GetPosition();
	void SetPosition(sf::Vector2f & POS);
};

