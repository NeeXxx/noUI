#include "bomb.h"

bomb::bomb(QFrame* parent,int tx,int ty,int tp,player* str):
    QFrame(parent),x(tx),y(ty),power(tp),setter(str)
{
    timer.start(3000,this);
}

void bomb::timerEvent(QTimerEvent* event)
{
    if(event->timerId()==timer.timerId())
    {
        emit explode(*this);
    }
}

