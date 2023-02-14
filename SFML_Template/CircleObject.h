#pragma once
#include "Object.h"
#include <TGUI/TGUI.hpp>
// originally supposed to be where the object is defined as a circle, however that function was dropped and it is unnecessary to drop this class.
class CircleObject :
    public Object
{
public:
    //Default size
    int Size = 50;

    void init();
    CircleObject();};