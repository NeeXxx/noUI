#include "block.h"

void block::destroyAbove()
{
    a=aAir;
}

void block::addAbove(above ta)
{
    a=ta;
}

bool block::haveFlame()
{
    return a==aArrowDown ||
           a==aArrowLeft ||
           a==aArrowRight ||
           a==aArrowUp;
}

void block::setUnder(under tu)
{
    u=tu;
}

bool block::inable()
{
    return u.inable() && a.inable();
}

bool block::pushable()
{
    return a.pushable();
}

bool block::hidable()
{
    return u.substance()==tree;
}

bool block::haveAbove()
{
    return a.substance()!=air;
}

substance block::appearance()
{
    if(hidable())
        return substance(u.substance(),air);
    else
        return substance(u.substance(),a.substance());
}

bool block::canExplode()
{
    if((u==uHouse) || (u==uWater))
        return false;
    return true;
}

void block::explode(direction dir)
{
    destroyAbove();
    addAbove(arrows[dir]);
}
