#include "block.h"

void block::destroyAbove()
{
    a=aAir;
}

void block::addAbove(above ta)
{
    a=ta;
}

void block::theBombExplode()
{
    delete theBomb;
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
    {
        if(middle==aP1ob)
            return substance(u.substance(),middle.substance());
        else
            return substance(u.substance(),a.substance());
    }
}

bool block::canBeExploded()
{
    if((u==uHouse) || (u==uWater))
        return false;
    return true;
}

void block::beExploded(direction dir)
{
    destroyAbove();
    addAbove(arrows[dir]);
}

void block::addBomb(player& p)
{
    middle=aP1ob;
}

bool block::haveBomb()
{
    return theBomb!=NULL;
}

void block::checkBomb()
{
    if(middle==aP1ob && a==aAir)
    {
        middle=aAir;
        a=aBomb;
    }
}
