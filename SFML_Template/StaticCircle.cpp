#include "StaticCircle.h"

void StaticCircle::init(int m)
{
	mass = m;
	Size = mass / 2;
}

StaticCircle::StaticCircle(int m)
{
	init(m);
}
