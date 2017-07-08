#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QBasicTimer>
#include "player.h"

class bomb
{
    //Q_OBJECT
public:
    bomb(int,int,int,int,player*);
    //bomb(bomb&);
    int getPower() const { return power; }
    bool canExplode(int);
    int getX() { return x; }
    int getY() { return y; }
    player* getSetter() { return setter; }//也可以用信号和槽来实现
    //~bomb();

//public slots:
    void explode(bomb&);

private:
    int x,y;
    int power;
    int setTime;
    player* setter;
    //QBasicTimer timer;

    const int explodeTime=15;

protected:
    //void timerEvent(QTimerEvent*) override;
};

#endif // BOMB_H
