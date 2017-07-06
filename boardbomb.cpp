#include "board.h"

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
    /*
    (player&) p[3]={0,p1,p2};
    int x=b.getX(),y=b.getY();
    p[b.getSetter()].bombExplode();
    int power=b.getPower();

    int tx=x,ty=y;
    while(m.blockAt(tx,ty).canExplode())
    {
        m.blockAt(tx,ty).explode();
    }
    */
}
