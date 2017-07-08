#ifndef DIRECTION_H
#define DIRECTION_H

//和方向有关的地方，方向的顺序必须都是【上、下、左、右】

enum direction{dirUp,dirDown,dirLeft,dirRight};

const above arrows[4]={aArrowUp,aArrowDown,aArrowLeft,aArrowRight};

const int dx[4]={ -1, 1,  0, 0},
          dy[4]={  0, 0, -1, 1};

#endif // DIRECTION_H
