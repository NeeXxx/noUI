#include "player.h"

player::player(QFrame* parent,int tx,int ty,above ta)
    :QFrame(parent),onBomb(ta)
{
    x=tx,y=ty;
    bombPower=2;
    bombNum=1;
    bombLeft=1;
    speed=1;
    timer.start(100,this);
}

void player::setBomb()
{
    bombLeft--;
}

#include <QDebug>
#define ANGRY qDebug()<<"angry!"<<endl;
void player::bombExplode(const bomb&)
{
    bombLeft++;
}

bool player::canSetBomb()
{
    return bombLeft>0;
}

void player::beTrapped()
{
    //x=0,y=0;
}

void player::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.translate(0,16);
    QPixmap pix;
    pix.load(":/images/images/player1.png");
    painter.drawPixmap(80*x-80,80*y-96,80,96,pix);
    //ANGRY
}

void player::timerEvent(QTimerEvent* event)
{
    if(event->timerId()==timer.timerId())
    {
        //repaint();
    }
}
