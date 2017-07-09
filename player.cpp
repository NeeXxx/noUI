#include "player.h"

//player::player()
//{
//    x=1,y=1;
//    bombPower=1;
//    bombNum=1;
//    bombLeft=1;
//    speed=1;
//}

player::player(int tx,int ty,above ta):onBomb(ta)
{
    x=tx,y=ty;
    bombPower=2;
    bombNum=1;
    bombLeft=1;
    speed=1;
}

void player::setBomb()
{
    bombLeft--;
}

void player::bombExplode()
{
    bombLeft++;
}

bool player::canSetBomb()
{
    return bombLeft>0;
}

void player::beTrapped()
{
    x=0,y=0;
}
