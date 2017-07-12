#include "gameobject.h"

gameObject::gameObject()
{

}

void gameObject::move(enum direction dir)
{
    x+=dx[dir],y+=dy[dir];
}

block& gameObject::getTheBlock()
{
    return *theBlock;
}

void gameObject::timerEvent(QTimerEvent* event)
{
    if(event->timerId()==updateTimer.timerId())
    {
        update();
    }
}
