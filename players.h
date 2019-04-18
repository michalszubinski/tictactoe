#ifndef PLAYERS_H_INCLUDED
#define PLAYERS_H_INCLUDED

#include "znak.h"

//players.cpp
void TURN(bool t, team Act, char *Map,_ob *t0, _ob *t1,char n=3); //turn i decide
c turn(bool t, team Act, char *Map, char n=3); // odwraca mape dla druzyny 1
c decide(bool t, team Act, char *Map, char n=3); // decyduje
void changer(bool t,c pos,_ob *t0, _ob *t1, char n=3); // zastosowuje ruch
bool possible(char *Map,c MOVE,bool team, char n=3);// czy ruch jest mozliwy

//player0.cpp
c player0(char *Map, char n=3); //ruch gracza - aktualnie brak

//player1.cpp
c player1(char *Map, char n=3); //ruch AI randomowego

//player2.cpp minimax

//player3.cpp samouczacy - do poprawki
struct can
{
    char i;
    string go;
    bool block;
};

c player3(char *Map,bool t, char n=3);
string actmap(char * Map, char n=3);
string loadprev(char * Map,bool t, char n=3);
string takename(char *Map,string adress, char n=3);
bool loadblock(string adress);
void blacklist(string adress);
string saveadress(char*Map,bool t,char n=3);
void cleanadress();

#endif // PLAYERS_H_INCLUDED
