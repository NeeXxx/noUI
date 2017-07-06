#include "bomb.h"
#include "widget.h"

void bomb::explode()
{
}

bool bomb::canExplode(int time)
{
    return time-setTime>=explodeTime;
}
