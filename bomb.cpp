#include "bomb.h"

bomb::bomb(QFrame* parent,int tx,int ty,int tp,player* str):
    QFrame(parent),x(tx),y(ty),power(tp),setter(str)
{
    timer.start(1500,this);
    exploded=false;
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
    qDebug()<<"besile"<<endl;
    exploded=true;
}

void bomb::tryExplode()
{
    qDebug()<<"BE"<<endl;
    if(!exploded)
    {
        qDebug()<<"angry"<<endl;
        setExploded();
        emit explode(*this);
    }
}
//=======
//>>>>>>> b983aedae3197ff03680f7cf948d84e1d4a2fcfc
