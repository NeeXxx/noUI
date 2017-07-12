#ifndef SUBSTANCES_H
#define SUBSTANCES_H

enum underSubstance{water,house,ground,tree,bridge};//枚举的顺序和数组的顺序关联，因而会影响初始化
enum aboveSubstance{sBomb,arrowUp,arrowDown,arrowLeft,arrowRight,
                    player1,player2,
                    wood,air,
                    bubble,shoe,drug,
                    p1ob,p2ob,
                    flame};

//希望底部的东西是不可改变的
class under
{
    underSubstance s;
    bool canBeIn;
public:
    under(underSubstance us,bool cbi):s(us),canBeIn(cbi) {}
    bool inable() { return canBeIn; }
    underSubstance substance() { return s; }
    bool operator== (const under right) const
    {
        return s==right.s && canBeIn==right.canBeIn;
    }
};

const under uWater(water,false),
            uHouse(house,false),//不可进入
            uGround(ground,true),
            uTree(tree,true),
            uBridge(bridge,true);//可进入

const under uArray[5]={uWater,uHouse,uGround,uTree,uBridge};

class above
{
    aboveSubstance s;
    bool canBeIn;
    bool canBePush;
public:
    above(aboveSubstance as,bool cbi,bool cbp):s(as),canBeIn(cbi),canBePush(cbp) {}
    bool pushable() { return canBePush; }
    bool inable() { return canBeIn; }
    aboveSubstance substance() { return s; }
    bool operator== (const above& right) const
    {
        return s==right.s &&
                canBeIn==right.canBeIn &&
                canBePush==right.canBePush;
    }
};

const above aBomb(sBomb,false,false),//不可推
            aWood(wood,false,true),//可推        //不可进入
            aArrowUp(arrowUp,true,false),
            aArrowDown(arrowDown,true,false),
            aArrowLeft(arrowLeft,true,false),
            aArrowRight(arrowRight,true,false),
            aPlayer1(player1,true,false),
            aPlayer2(player2,true,false),
            aAir(air,true,false),
            aBubble(bubble,true,false),
            aShoe(shoe,true,false),
            aDrug(drug,true,false),
            aP1ob(p1ob,true,false),
            aP2ob(p2ob,true,false),
            aFlame(flame,true,false);//可进入

const above aArray[15]={aBomb,aArrowUp,aArrowDown,aArrowLeft,aArrowRight,
                    aPlayer1,aPlayer2,
                    aWood,aAir,
                    aBubble,aShoe,aDrug,
                    aP1ob,aP2ob,
                    aFlame};

class substance
{
public:
    underSubstance us;
    aboveSubstance as;
    substance(underSubstance tus,aboveSubstance tas):us(tus),as(tas) {}
    substance() {}
};

#endif // SUBSTANCES_H
