#ifndef FX_H_INCLUDED
#define FX_H_INCLUDED

#include "znak.h"

//game.cpp
char endd(_ob *t0, _ob *t1,char *Map, char n=3); // 1 - Druzyna 0; 2 - Druzyna 1; 3 - Remis; 0 - Nic (czy koniec)
bool check(_ob *tab, char n=3); // czy druzyna wygrala
bool draw(char *Map, char n=3); // czy remis
c rev(c pos, bool t=1, char n=3); // odwrocenie pozycji
void lm(char *Map, _ob *t0, _ob *t1, char n=3); // wczytaj mape
void Ltofx(char *Map,char *MA,bool t, char n=3); // odwrocenie mapy dla graczy
bool changeact(bool act); // zmiana tury
void ini(_ob *t0, _ob *t1,char *Map, char n=3); // inicjalizacja gry
c itoc(char I, char n=3); // liczbe zamienia na pozycje (np 3 = (0,1), 7 = (1,2) itp)
char ctoi(c pos, char n=3); // zamienia pozycje na liczbe (np (2,0) = 2, (1,0) = 3 itp)

//view.cpp
void MAP(char *Map, _ob *t0, _ob *t1, char n=3); // lm i pm
void pm(char *Map, char n=3); //narysuj mape
void ppos(c pos); //narysuj pozycje
void palive(_ob *t0, _ob *t1, char n=3); //kto jest zywy
void pruch(bool t); // wyswietla ktora druzyna ma ruch


#endif // FX_H_INCLUDED
