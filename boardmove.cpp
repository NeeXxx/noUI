#include "board.h"

bool board::tryMove(player& p,direction dir)
{
    int x=p.getX(),y=p.getY();
    bool flag=tryMove(x,y,x+dx[dir],y+dy[dir]);
    if(flag) p.move(dx[dir],dy[dir]);
    return flag;
}

bool board::tryMove(int x1,int y1,int x2,int y2) //from 1 to 2
{
    if(!inMap(x2,y2))
        return false;
    block& target=m.blockAt(x2,y2);
    if(target.inable())
    {
        if(target.hidable())
            return tryInToHide(x1,y1,x2,y2);
        else
        {
            return trySimpleMove(x1,y1,x2,y2);
        }
    }
    else
    {
        if(target.pushable())
            return tryPush(x1,y1,x2,y2);
        else
        {
            return false;
        }
    }
}
//bug?

bool board::trySimpleMove(int x1,int y1,int x2,int y2)
{
    m.moveAToB(x1,y1,x2,y2);
    return true;
}

bool board::tryPush(int x1,int y1,int x2,int y2)
{
    block& target1=m.blockAt(x2,y2);
    int x3=x2+x2-x1,y3=y2+y2-y1;
    if(!inMap(x3,y3))
        return false;
    block& target2=m.blockAt(x3,y3);

    bool flag;
    if(target2.inable())
    {
        if(target2.hidable())
        {
            flag=tryInToHide(x2,y2,x3,y3);
            if(target1.hidable())
                tryInToHide(x1,y1,x2,y2);
            else
                trySimpleMove(x1,y1,x2,y2);
        }
        else
        {
            flag=trySimpleMove(x2,y2,x3,y3);
            if(target1.hidable())
                tryInToHide(x1,y1,x2,y2);
            else
                trySimpleMove(x1,y1,x2,y2);
        }
    }
    else
        return false;
    return flag;
}

bool board::tryInToHide(int x1,int y1,int x2,int y2)
{
    m.moveAToB(x1,y1,x2,y2);
    return true;
}
