#include "board.h"
#include "gameover.h"
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <map>
#include <string>
using namespace  std;

board::board(QWidget* parent):QFrame(parent),p1(this,1,1,aP1ob),p2(this,9,9,aP2ob)
{
    //merge
    //qDebug()<<"angry"<<endl;
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
    cnt=0;
    timer.start(200,this);
    resize(1200,720);

    initPlayer1();
    initPlayer2();

    connect(this,SIGNAL(signalTrapPlayer(player&)),
            this,SLOT(end(player&)));
}

QSize board::sizeHint() const
{
    return QSize(1200,720);
}

QSize board::minimumSizeHint() const
{
    return QSize(1200,720);
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

            if(i==x1 && j==y1) temp.addAbove(aPlayer1);
            if(i==x2 && j==y2) temp.addAbove(aPlayer2);

            mapForDraw[i][j]=temp.appearance();
        }
}

bool board::inMap(int x,int y)
{
    return x>=1 && x<=9 && y>=1 && y<=9;
}

void board::end(player& p)
{
    gameOver g(this);
    g.setWindowTitle(QObject::tr("游戏结束啦"));
    g.setWindowIcon(QIcon(":/images/images/Logo.png"));
    if(p==p1) //p1输了
    {
        g.setLoser(1);
    }
    else //p2输了
    {
        g.setLoser(2);
    }
    g.exec();
}
