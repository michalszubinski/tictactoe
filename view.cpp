#include <iostream>
#include <stdio.h>

#include "znak.h"
#include "fx.h"

using namespace std;

void MAP(char *Map, _ob *t0, _ob *t1, char n)
{
    lm(Map,t0,t1);
    pm(Map);
}

void pm(char *Map, char n)
{
    cout<<"    0 1 2 [X]\n\n";
    for(char i = 0; i<n; i++) //y
    {
        cout<<" "<<(int)i<<"  ";
        for(char j = 0; j<n; j++) //x
        {
            switch(Map[j+(i*n)])
            {
            case 0:
                {
                    cout<<"X ";
                }break;
            case 1:
                {
                    cout<<"O ";
                }break;
            case 2:
                {
                    cout<<"- ";
                }break;
            }
        }
        cout<<endl;
    }
    cout<<"[Y]\n\n";
}

void ppos(c pos)
{
    printf("\nx:%d y:%d\n",(int)pos.x,(int)pos.y);
}

void palive(_ob *t0, _ob *t1, char n)
{
    for(char i=0; i<n*n;i++)
    {
        if(t0[i].alive==1) printf("Team 0 [%d]: alive\n",(int)i);
        if(t1[i].alive==1) printf("Team 1 [%d]: alive\n",(int)i);
    }
}

void pruch(bool t)
{
    printf("Ruch druzyny %d!\n",t);
}
