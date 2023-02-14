#pragma once
#include "CircleObject.h"
class StaticCircle :
    public CircleObject
{
public:
    //m is mass, the only reason why it's not size is so I can use the same number on this class and movingcircle for the same size
    void init(int m);
    StaticCircle(int m);
};

