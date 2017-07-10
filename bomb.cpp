#include "bomb.h"

bomb::bomb(QFrame* parent,int tx,int ty,int tp,player* str):
    QFrame(parent),x(tx),y(ty),power(tp),setter(str)
{
    timer.start(1500,this);
}

void bomb::timerEvent(QTimerEvent* event)
{
    if(event->timerId()==timer.timerId())
    {
        tryExplode();
    }
}
//<<<<<<< HEAD


void bomb::setExploded()
{
    exploded=true;
}

void bomb::tryExplode()
{
    if(!exploded)
        emit explode(*this);
}
//=======
//>>>>>>> b983aedae3197ff03680f7cf948d84e1d4a2fcfc
