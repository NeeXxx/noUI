#include "board.h"
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <map>
#include <string>
using namespace  std;

board::board(QWidget* parent):QFrame(parent),p1(1,1),p2(3,8)
{
    //merge
    //qDebug()<<"angry"<<endl;
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
    cnt=0;
    timer.start(200,this);
    resize(1000,1000);

    initPlayer1();
    initPlayer2();
}

QSize board::sizeHint() const
{
    return QSize(1000,1000);
}

QSize board::minimumSizeHint() const
{
    return QSize(1000,1000);
}

void board::initPlayer1()
{
    int x=p1.getX(),y=p1.getY();
    m.blockAt(x,y).addAbove(aPlayer1);
}

void board::initPlayer2()
{
    int x=p2.getX(),y=p2.getY();
    m.blockAt(x,y).addAbove(aPlayer2);
}

void board::countMapForDraw()
{
    int x1=p1.getX(),y1=p1.getY(),
        x2=p2.getX(),y2=p2.getY();

    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
        {
            block& temp=m.blockAt(i,j);
            if(temp.haveBomb() && temp.getAbove()==aAir)
            {
                temp.removeMiddle();
                temp.addAbove(aBomb);
            }

            if(i==x1 && j==y1) temp.addAbove(aPlayer1);
            if(i==x2 && j==y2) temp.addAbove(aPlayer2);

            mapForDraw[i][j]=temp.appearance();
        }
}

bool board::inMap(int x,int y)
{
    return x>=1 && x<=9 && y>=1 && y<=9;
}
