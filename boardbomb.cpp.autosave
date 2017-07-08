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
    p.setBomb();
    bombQueue.push(bomb(x,y,p.getBombPower(),cnt,&p));
}//绘图是个问题



void board::setFlame(bomb b,direction dir)
{
    int x=b.getX(),y=b.getY();
    int power=b.getPower();

    for(int i=0,tx=x,ty=y;m.blockAt(tx,ty).canExplode() && (i<=power);i++)
    {
        m.blockAt(tx,ty).explode(dir);
        tryTrapPlayer(tx,ty);
        tx+=dx[dir],ty+=dy[dir];
    }
}

void board::explode(bomb b)
{
    b.getSetter()->bombExplode();

    for(int dir=dirUp;dir<=dirRight;dir++)
        setFlame(b,(direction)dir);
}
