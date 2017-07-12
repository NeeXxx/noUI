#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QFrame>
#include <QTimer>
#include "direction.h"
#include "block.h"
#include "myMap.h"

class block;
class myMap;

class gameObject:public QFrame
{
    Q_OBJECT
public:
    gameObject();
    void move(direction); // imp
    block& getTheBlock(); //imp

signals:
    void beDestroyed();
private:
    int x,y;
    QBasicTimer updateTimer;
    block* theBlock;
protected:
    //void paintEvent(QPaintEvent*);
    //void keyPressEvent(QKeyEvent*);
    void timerEvent(QTimerEvent*);
};

#endif // GAMEOBJECT_H
