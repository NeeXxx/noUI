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
    theBomb=NULL;
}

bool block::haveFlame()
{
    return a==aArrowDown ||
           a==aArrowLeft ||
           a==aArrowRight ||
           a==aArrowUp ||
           a==aFlame;
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
    checkBomb(); //先检测比较稳妥
    if(hidable())
        return substance(u.substance(),air);
    else
    {
        if(middlePlayerOnBomb())
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
    if(haveBomb())
    {
        theBomb->tryExplode();
    }
}

void block::addBomb(player& p)
{
    middle=p.onBomb;
}

bool block::haveBomb()
{
    return theBomb!=NULL;
}

bool block::middlePlayerOnBomb()
{
    return middle==aP1ob || middle==aP2ob;
}

void block::checkBomb()
{
    if(middlePlayerOnBomb() && a==aAir) //表明人已经走了，此地只剩下bomb
    {
        middle=aAir;
        a=aBomb;
    }
}

bool block::havePlayer()
{
    return a==aPlayer1 || a==aPlayer2;
}
