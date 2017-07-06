#ifndef BOARD_H
#define BOARD_H

#include "myMap.h"
#include "player.h"
#include "block.h"
#include "bomb.h"
#include <QtWidgets>
#include <QBasicTimer>
#include <QFrame>
#include <QPointer>
#include <queue>


class board:public QFrame
{
public:
    board(QWidget* parent=0);

    bool tryMoveUp(player&);
    bool tryMoveDown(player&);
    bool tryMoveLeft(player&);
    bool tryMoveRight(player&);

    void trySetBomb(player&);
    void setBomb(player&);

    void countMapForDraw();
    substance mapForDraw[10][10];

    void keyPressEvent(QKeyEvent* event) Q_DECL_OVERRIDE;

private:

    myMap m;
    std::queue<bomb> bombQueue;

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

    QBasicTimer timer;
    int cnt;

    bool trySimpleMove(int x1,int y1,int x2,int y2);
    bool tryPush(int x1,int y1,int x2,int y2);
    bool tryInToHide(int x1,int y1,int x2,int y2);

    bool tryMove(int x1,int y1,int x2,int y2);

    void explode(class bomb);

    bool inMap(int x,int y);

    void initPlayer1();
    void initPlayer2();

protected:
    void paintEvent(QPaintEvent*) override;
    void timerEvent(QTimerEvent*) override;
    player p1,p2;
};

#endif // BORAD_H
