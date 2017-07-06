#include "board.h"

void board::tryTrapPlayer(int tx,int ty)
{
    int x1=p1.getX(),y1=p1.getY(),
        x2=p2.getX(),y2=p2.getY();

    if(tx==x1 && ty==y1)
        p1.beTrapped();
    if(tx==x2 && ty==y2)
        p2.beTrapped();
}

void board::trapPlayer(player& p)
{
    p.beTrapped();
}
