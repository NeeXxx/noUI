#ifndef BOMB_H
#define BOMB_H

#include "player.h"

class bomb
{
public:
    bomb(int tx,int ty,int tp,int tst,player* str):
        x(tx),y(ty),power(tp),setTime(tst),setter(str) {}
    int getPower() const { return power; }
    void explode();
    bool canExplode(int);
    int getX() { return x; }
    int getY() { return y; }
    player* getSetter() { return setter; }

private:
    int x,y;
    int power;
    int setTime;
    player* setter;

    const int explodeTime=15;
};

#endif // BOMB_H
