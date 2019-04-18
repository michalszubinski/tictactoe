#include <iostream>
#include <windows.h>
#include <ctime>

#include "znak.h"
#include "fx.h"
#include "players.h"

using namespace std;

char _ob::n0=0;
char _ob::n1=0;

int main()
{
    srand( time( NULL ) );

    for(int i = 0; i<1000; i++)
    {
        _ob *t0 = new _ob[9];
        _ob *t1 = new _ob[9];
        char *Map = new char[9];
        team T0(0,1);
        team T1(1,1);
        bool act=0;
        ini(t0,t1,Map);

        //cout<<(int)endd(t0,t1,Map);
        //lm(Map,t0,t1);

        MAP(Map,t0,t1);
        while(!endd(t0,t1,Map))
        {
            //pm(Map);
            //pruch(act);
            if(act==0) TURN(act,T0,Map,t0,t1);
            else TURN(act,T1,Map,t0,t1);


            act = changeact(act);
            //lm(Map,t0,t1);
            MAP(Map,t0,t1);
            palive(t0,t1);
            system("pause");
        }
        pm(Map);

        cout<<"elo - ";
        cout<<(int)endd(t0,t1,Map)<<endl;
        system("pause");


        cleanadress();
        delete [] t0;
        delete [] t1;
        delete [] Map;
    }
}
