#include "board.h"

void board::paintEvent(QPaintEvent*)
{
    //绘制地图底板
    QPainter painter(this);
    painter.translate(0,16);
    QPixmap tground;
    tground.load(":/images/images/ground.png");
    painter.drawPixmap(0,0,1200,720,tground);
    //绘制前的定义
    std::map<aboveSubstance,QString> aM;
    std::map<underSubstance,QString> uM;
    aM[player1]="player1.png";
    aM[player2]="player2.png";
    aM[wood]="wood.png";
    aM[sBomb]="bomb.png";
    aM[p1ob]="player1_on_bomb.png";
    aM[p2ob]="player2_on_bomb.png";
    aM[arrowDown]="flame_down.png";
    aM[arrowUp]="flame_up.png";
    aM[arrowLeft]="flame_left.png";
    aM[arrowRight]="flame_right.png";
    aM[flame]="flame.png";
    uM[house]="house.png";
    uM[tree]="tree.png";
    uM[water]=uM[ground]=uM[bridge]="blank.png";
    QString name, full_name;
    //绘制每格元素
    countMapForDraw();
    QPixmap pix;
    for (int i=1;i<10;i++)
    {
        for (int j=1;j<10;j++)
        {
            substance judge=mapForDraw[j][i];
            if (judge.as!=air)
            {
                name=aM[judge.as];
            }
            else
            {
                name=uM[judge.us];
            }
            full_name=":/images/images/"+name;
            pix.load(full_name);
            painter.drawPixmap(80*i-80,80*j-96,80,96,pix);
        }
    }
}
//*/

void board::keyPressEvent(QKeyEvent* event)
{
    static map<int,direction> p1KTD,p2KTD; // key to direction
    p1KTD[Qt::Key_W]=dirUp;
    p1KTD[Qt::Key_S]=dirDown;
    p1KTD[Qt::Key_A]=dirLeft;
    p1KTD[Qt::Key_D]=dirRight;

    p2KTD[Qt::Key_Up]=dirUp;
    p2KTD[Qt::Key_Down]=dirDown;
    p2KTD[Qt::Key_Left]=dirLeft;
    p2KTD[Qt::Key_Right]=dirRight;

    if(p1KTD.count(event->key()))
        tryMove(p1,p1KTD[event->key()]);
    if(p2KTD.count(event->key()))
        tryMove(p2,p2KTD[event->key()]);
    switch(event->key())
    {
    //p1:
    case Qt::Key_J:
        trySetBomb(p1);
        break;

    //p2:
    case Qt::Key_Space:
        trySetBomb(p2);
        break;
    }
    repaint();
}

void board::timerEvent(QTimerEvent* event)
{
    if(event->timerId()==timer.timerId())
    {
        cnt++;
        repaint();
        m.cleanFlames();
    }
}
