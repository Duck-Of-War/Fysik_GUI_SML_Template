#include "StaticCircle.h"


//Sets all parameters for static circle
void StaticCircle::init(int m)
{
	mass = m;
	Size = mass;
	Circle.setRadius(Size);
	Circle.setFillColor(sf::Color(207, 191, 178));
}

StaticCircle::StaticCircle(int m)
{
	init(m);
}
