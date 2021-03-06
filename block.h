#ifndef BLOCK_H
#define BLOCK_H

#include "substances.h"
#include "direction.h"
#include "bomb.h"

class bomb;

class block//:public QFrame
{
    //Q_OBJECT
    under u;
    above a;
    above middle; //用来表示人和炸弹在同一块的情况
    //bool havePlayer;
public:
    bomb* theBomb;

    void theBombExplode();

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

    bool havePlayer();

    bool haveBomb();
    void addBomb(player&);
    void checkBomb();
    bool middlePlayerOnBomb();
};

#endif // BLOCK_H
