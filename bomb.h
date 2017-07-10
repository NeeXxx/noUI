#ifndef BOMB_H
#define BOMB_H

#include <QtWidgets>
#include <QFrame>
#include <QBasicTimer>
#include <QTimer>
#include "player.h"
#include "block.h"

class player;

class bomb:public QFrame
{
    Q_OBJECT
public:
    bomb(QFrame*,int,int,int,player*);
    int getPower() const { return power; }
    int getX() const { return x; }
    int getY() const { return y; }
    player* getSetter() const { return setter; }//也可以用信号和槽来实现
    //block& getBlock();
    //~bomb() {}
    void tryExplode(); //可以返回bool

signals:
    void explode(const bomb&);

public slots:
    void setExploded();

private:
    int x,y;
    int power;
    player* setter;
    QBasicTimer timer;

    bool exploded;

protected:
    void timerEvent(QTimerEvent*) override;
};

#endif // BOMB_H
