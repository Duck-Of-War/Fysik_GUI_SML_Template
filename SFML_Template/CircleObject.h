#pragma once
#include "Object.h"
#include <TGUI/TGUI.hpp>

class CircleObject:
    public Object
{
    int Size;
    bool is_red;
    void init();

    CircleObject();
};

