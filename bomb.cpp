#include "bomb.h"
#include "widget.h"

bomb::bomb(int tx,int ty,int tp,int tst,player* str):
    x(tx),y(ty),power(tp),setTime(tst),setter(str)
{
    //timer.start(3000,this);
}

void bomb::explode(bomb&)
{
}

bool bomb::canExplode(int time)
{
    return time-setTime>=explodeTime;
}

/*void bomb::timerEvent(QTimerEvent* event)
{
    if(event->timerId()==timer.timerId())
    {
        emit explode(*this);
    }
}*/
