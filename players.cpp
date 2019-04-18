#include <iostream>
#include <windows.h>

#include "znak.h"
#include "players.h"
#include "fx.h"

using namespace std;

void TURN(bool t, team Act, char *Map,_ob *t0, _ob *t1,char n)
{
    c MOVE = turn(t,Act,Map);
    changer(t,MOVE,t0,t1);
    //ppos(MOVE);
}

c turn(bool t, team Act, char *Map, char n)
{
    char *NewM = new char[n*n];
    Ltofx(Map,NewM,t);


    c Move = decide(t,Act,NewM);
    //cout<<(int)Move.x<<endl<<(int)Move.y<<endl;

    if(t==0) return Move;
    else return rev(Move,1);
}

c decide(bool t, team Act, char *Map, char n)
{
    switch(Act.playertype)
    {
    case 0: break;
    case 1: return player1(Map); break;
    case 2: break;
    case 3: return player3(Map,t); break;
    }
}

void changer(bool t,c pos,_ob *t0, _ob *t1, char n)
{
    //cout<<pos.y*n + pos.x<<endl;
    //ppos(pos);
    switch(t)
    {
    case 0: t0[pos.y*n + pos.x].alive=1; break;
    case 1: t1[pos.y*n + pos.x].alive=1; break;
    }
}

bool possible(char *Map,c MOVE,bool team, char n)
{
    if((int)Map[MOVE.y*n + MOVE.x]==2) return 1;
    else return 0;
}
