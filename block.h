#ifndef BLOCK_H
#define BLOCK_H

#include "substances.h"
#include "direction.h"
#include "bomb.h"

class block
{
    under u;
    above a;
    above middle; //用来表示人和炸弹在同一块的情况
public:
    bomb* theBomb;

    //friend void myMap::intToBlock();
public:
    block(under tu,above ta):u(tu),a(ta),middle(aAir),theBomb(NULL) {}
    block(under tu):u(tu),a(aAir),middle(aAir),theBomb(NULL) {}
    block():u(uWater),a(aAir),middle(aAir),theBomb(NULL) {}

    void destroyAbove();
    void addAbove(above ta);
    above getAbove() { return a; }
    bool haveFlame();

    void setUnder(under tu);

    bool inable();
    bool pushable();
    bool hidable();
    bool haveAbove();

    bool canBeExploded();
    void beExploded(direction);

    substance appearance(); //画图必须调用appearance

    bool haveBomb() { return middle==aBomb; }
    void addBomb() { middle=aBomb; }
    void removeMiddle() { middle=aAir; }
};

#endif // BLOCK_H
