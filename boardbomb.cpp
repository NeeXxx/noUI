#include "board.h"
#include <QDebug>

#include <QDebug>
#define ANGRY qDebug()<<"angry"<<endl;
void board::trySetBomb(player& p)
{
    if(p.canSetBomb())
        setBomb(p);
}

void board::setBomb(player& p)
{
    int x=p.getX(),y=p.getY();
    myMap::getTheMap().blockAt(x,y).addBomb(p);
    p.setBomb();
    myMap::getTheMap().blockAt(x,y).theBomb=new bomb(this,x,y,p.getBombPower(),&p);
    connect(myMap::getTheMap().blockAt(x,y).theBomb,SIGNAL(explode(const bomb&)),
            &p,SLOT(bombExplode(const bomb&)));
    connect(myMap::getTheMap().blockAt(x,y).theBomb,SIGNAL(explode(const bomb&)),
            this,SLOT(exploded(const bomb&)));
}//绘图是个问题

void board::exploded(const bomb& b)
{
    for(int dir=dirUp;dir<=dirRight;dir++)
        setFlame(b,(direction)dir);
    myMap::getTheMap().blockAt(b.getX(),b.getY()).theBombExplode();ANGRY
}

void board::setFlame(const bomb& b,direction dir)
{
    int x=b.getX(),y=b.getY();
    int power=b.getPower();

    for(int i=0,tx=x,ty=y;
        inMap(tx,ty) && myMap::getTheMap().blockAt(tx,ty).canBeExploded() && (i<=power);
        i++)
    {
        if(!(tx==x && ty==y))
            myMap::getTheMap().blockAt(tx,ty).beExploded(dir);//
        tryTrapPlayer(tx,ty);
        tx+=dx[dir],ty+=dy[dir];
    }
    myMap::getTheMap().blockAt(x,y).addAbove(aFlame);
}
