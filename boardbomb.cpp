#include "board.h"
#include "direction.h"

void board:: trySetBomb(player& p)
{
    if(p.canSetBomb())
        setBomb(p);
}

void board::setBomb(player& p)
{
    int x=p.getX(),y=p.getY();
    m.blockAt(x,y).addBomb();

    bombQueue.push(bomb(x,y,p.getBombPower(),cnt));
}//绘图是个问题

void board::explode(bomb b)
{
    int x=b.getX(),y=b.getY();
    int setter=b.getSetter();
    if(setter==1)
        p1.bombExplode();
    else
        p2.bombExplode();
    int power=b.getPower();

    for(int i=0,tx=x,ty=y;m.blockAt(tx,ty).canExplode() && (i<=power);i++)
    {
        m.blockAt(tx,ty).explode(dirDown);
        tx++;
        tryTrapPlayer(tx,ty);
    }
    for(int i=0,tx=x,ty=y;m.blockAt(tx,ty).canExplode() && (i<=power);i++)
    {
        m.blockAt(tx,ty).explode(dirUp);
        tx--;
        tryTrapPlayer(tx,ty);
    }
    for(int i=0,tx=x,ty=y;m.blockAt(tx,ty).canExplode() && (i<=power);i++)
    {
        m.blockAt(tx,ty).explode(dirRight);
        ty++;
        tryTrapPlayer(tx,ty);
    }
    for(int i=0,tx=x,ty=y;m.blockAt(tx,ty).canExplode() && (i<=power);i++)
    {
        m.blockAt(tx,ty).explode(dirLeft);
        ty--;
        tryTrapPlayer(tx,ty);
    }
}
