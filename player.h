#ifndef PLAYER_H
#define PLAYER_H

#include <QFrame>
#include "substances.h"
#include "bomb.h"

class bomb;

class player:public QFrame
{
    Q_OBJECT
public:
    //player();
    player(QFrame*,int,int,above);

    above onBomb;

    int getSpeed() const { return speed; }
    void setSpeed(int t) { speed=t; }
    int getBombPower() const {return bombPower; }
    void setBombPower(int t) { bombPower=t; }
    int getX() { return x; }
    int getY() { return y; }

    void move(int dx,int dy) { x+=dx; y+=dy; }

    void setBomb();

    bool operator==(const player& right) const
    {
        return onBomb==right.onBomb;
    }

    //~player();
public slots:
    void bombExplode(const bomb&);

    bool canSetBomb();

    void beTrapped();

private:
    int speed;
    int bombPower;
    int bombNum; //总共能放多少个炸弹
    int bombLeft; //还能放多少个炸弹
    int x,y;
    QBasicTimer timer;

protected:
    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent*);
};

#endif // PLAYER_H
