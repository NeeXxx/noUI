#include "board.h"
#include <QDebug>

void board::trySetBomb(player& p)
{
    if(p.canSetBomb())
        setBomb(p);
}

void board::setBomb(player& p)
{
    int x=p.getX(),y=p.getY();
    m.blockAt(x,y).addBomb(p);
    p.setBomb();
    m.blockAt(x,y).theBomb=new bomb(this,x,y,p.getBombPower(),&p);
    connect(m.blockAt(x,y).theBomb,SIGNAL(explode(const bomb&)),
            this,SLOT(exploded(const bomb&)));
}//绘图是个问题

void board::exploded(const bomb& b)
{
    b.getSetter()->bombExplode();

    for(int dir=dirUp;dir<=dirRight;dir++)
        setFlame(b,(direction)dir);
    m.blockAt(b.getX(),b.getY()).theBombExplode();
}

void board::setFlame(const bomb& b,direction dir)
{
    int x=b.getX(),y=b.getY();
    int power=b.getPower();

    for(int i=0,tx=x,ty=y;
        inMap(tx,ty) && m.blockAt(tx,ty).canBeExploded() && (i<=power);
        i++)
    {
        if(!(tx==x && ty==y))
            m.blockAt(tx,ty).beExploded(dir);//
        tryTrapPlayer(tx,ty);
        tx+=dx[dir],ty+=dy[dir];
    }
    m.blockAt(x,y).addAbove(aFlame);
}
