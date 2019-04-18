#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>

#include "znak.h"
#include "players.h"
#include "fx.h"

using namespace std;


c player3(char *Map,bool t, char n)
{
    string adress = saveadress(Map,t);
    char nr=0;
    char nr2=0;
    char moveid;
    c MOVE;

    for(char i=0; i<n*n; i++)
    {
        if(possible(Map,itoc(i),t)) nr++;
    }

    can *c = new can[nr];

    {
        char nr3=0;
        for(char i=0; i<n*n; i++)
        {
            if(possible(Map,itoc(i),t))
            {
                c[i].i=nr3;
                nr3++;
            }
        }
    }

    for(char i=0; i<nr; i++)
    {
        ppos(itoc(c[nr2].i));
        c[i].go = takename(Map,adress);
        c[i].block = loadblock(c[i].go);

        if(!c[i].block) nr2++;
    }


    if(nr2<0)
    {
        blacklist(adress);
        moveid = (char)(rand() % nr);
        MOVE = itoc(c[moveid].i);
        delete [] c;

        return MOVE;
    }
    else
    {
        while(true)
        {
            moveid = (char)(rand() % nr);
            if(!c[moveid].block)
            {
                MOVE = itoc(c[moveid].i);
                delete [] c;

                return MOVE;
            }
        }
    }


}

string actmap(char * Map, char n)
{
    string ret="";
    string T="";

    for(char i=0; i<(n*n);i++)
    {
        /*ss<<(int)Map[i];
        ss>>t;*/
        T = Map[i]+48;
        ret+=T;
        //cout<<"elo"<<t<<endl;

        T="";
    }

    ret+=" ";
    return ret;
}

string loadprev(char * Map,bool t, char n)
{
    string linia;
    fstream plik;
    string filename;

    if(t==0) filename = "0AI_adress.txt";
    else filename = "1AI_adress.txt";

    plik.open(filename.c_str(), ios::in);
    if(plik.good() == true)
    {
        while(!plik.eof())
        {
            getline(plik, linia);
        }
        plik.close();
    }

    return linia;
}

string takename(char *Map,string adress, char n)
{
    return "XD";
}

bool loadblock(string adress)
{
    return 0;
}

void blacklist(string adress)
{
    if(!loadblock(adress))
    {
        string linia;
        fstream plik;

        plik.open("AI.txt", ios::out | ios::app);
        if(plik.good() == true)
        {
            plik << adress << endl;
            plik.close();
        }
    }
}

string saveadress(char*Map,bool t,char n)
{
    string act = actmap(Map);
    string prev = loadprev(Map,t);
    string adress = prev + act;
    string filename;


    string linia;
    fstream plik;

    if(t==0) filename = "0AI_adress.txt";
    else filename = "1AI_adress.txt";

    plik.open(filename.c_str(), ios::out | ios::trunc);
    if(plik.good() == true)
    {
        plik << adress;
        plik.close();
    }

    return adress;
}

void cleanadress()
{
    string linia;
    fstream plik;

    plik.open("AI_adress.txt", ios::out | ios::trunc);
    if(plik.good() == true)
    {
        plik.close();
    }

}
