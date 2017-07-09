#ifndef BOMB_H
#define BOMB_H

#include <QtWidgets>
#include <QFrame>
#include <QBasicTimer>
#include <QTimer>
#include "player.h"
#include "block.h"

class bomb:public QFrame
{
    Q_OBJECT
public:
    bomb(QFrame*,int,int,int,player*);
    int getPower() const { return power; }
    int getX() { return x; }
    int getY() { return y; }
    player* getSetter() { return setter; }//也可以用信号和槽来实现
    //block& getBlock();

signals:
    void explode(bomb&);

private:
    int x,y;
    int power;
    player* setter;
    QBasicTimer timer;

protected:
    void timerEvent(QTimerEvent*) override;
};

#endif // BOMB_H
