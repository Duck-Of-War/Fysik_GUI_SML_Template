#include "StaticCircle.h"

void StaticCircle::init(int m)
{
	mass = m;
	Size = mass;
	is_red = true;
	Circle.setFillColor(sf::Color(155, 0, 0));
	Circle.setRadius(Size);
}

StaticCircle::StaticCircle(int m)
{
	init(m);
}
