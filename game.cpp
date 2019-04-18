#include <iostream>
#include <stdio.h>

#include "znak.h"
#include "fx.h"

using namespace std;

char endd(_ob *t0, _ob *t1, char *Map, char n)
{
    if(check(t0)==1) return 1;

    if(check(t1)==1) return 2;

    if(draw(Map)==1) return 3;


    return 0;
}

bool check(_ob *tab, char n)
{
    c sr;
    sr.x=1;
    sr.y=1;

    for(char i=0; i<(n*n);i++)
    {
        for(char j=i+1; j<(n*n); j++)
        {
            for(char k=j+1; k<(n*n); k++)
            {

                if((tab[4].alive==1))
                {
                    if(((tab[0].alive==1)&&(tab[8].alive==1))||((tab[2].alive==1)&&(tab[6].alive==1)))
                    {
                        cout<<"skos\n";
                        return 1;
                    }
                }

                if((tab[i].alive==1)&&(tab[j].alive==1)&&tab[k].alive==1) //czy istnieja
                {
                    int xv=tab[i].pos.x;
                    int yv=tab[i].pos.y;

                    if((tab[j].pos.x==xv)&&(tab[k].pos.x==xv))
                    {
                        cout<<"x same\n";
                        /*printf("i: %d\nj: %d\nk: %d\n",(int)i,(int)j,(int)k);
                        ppos(tab[i].pos);
                        ppos(tab[j].pos);
                        ppos(tab[k].pos);*/
                        return 1;
                    }

                    if((tab[j].pos.y==yv)&&(tab[k].pos.y==yv))
                    {
                        cout<<"y same\n";
                        /*printf("i: %d\nj: %d\nk: %d\n",(int)i,(int)j,(int)k);
                        ppos(tab[i].pos);
                        ppos(tab[j].pos);
                        ppos(tab[k].pos);*/
                        return 1;
                    }

                }
            }
        }
    }

    return 0;
}

bool draw(char *Map, char n)
{
    for(char i=0; i<n*n; i++)
    {
        //cout<<(int)Map[i];
        if(Map[i]==2)
        {return 0;cout<<(int)i;}
    }
    //cout<<endl;
    return 1;
}

c rev(c pos, bool t, char n)
{
    if(t==1)
    {
        pos.x = 2 - pos.x;
        pos.y = 2 - pos.y;
        return pos;
    }
    else return pos;
}

void lm(char *Map, _ob *t0, _ob *t1, char n)
{
    c act;
    for(char i=0; i<n; i++) //y
    {
        for(char j=0;j<n;j++) //x
        {

            if(t0[j+(i*n)].alive==1)
            {
                Map[j+(i*n)]=0;
            }
            else if(t1[j+(i*n)].alive==1)
            {
                Map[j+(i*n)]=1;
            }
            else Map[j+(i*n)]=2;
        }
    }
}

void Ltofx(char *Map,char *MA,bool t, char n)
{
    switch(t)
    {
    case 0:
        {
            for(char i=0; i<n*n; i++)
            {
                MA[i]=Map[i];
            }

        } break;
    case 1:
        {
            char Mhelp[n*n];
            for(char i=0; i<n*n; i++)
                Mhelp[i]=Map[i];

            for(char i=0; i<n*n; i++)
            {
                MA[i]=Mhelp[(n*n)-i-1];
            }

        } break;
    }
}

bool changeact(bool act)
{
    if(act==0) return 1;
    else return 0;
}

void ini(_ob *t0, _ob *t1,char * Map, char n)
{
    for(char i=0; i<n;i++) //y
    {
        for(char j=0; j<n; j++) //x
        {
            t0[j + (i*n)].alive=0;
            t1[j + (i*n)].alive=0;
            t0[j + (i*n)].pos.x=j;
            t0[j + (i*n)].pos.y=i*n;
            t1[j + (i*n)].pos.x=j;
            t1[j + (i*n)].pos.y=i*n;

            Map[j + (i*n)]=2;
        }
    }
}

c itoc(char I, char n)
{
    c ret;

    ret.x = I % n;
    for(char i=0; i<n;i++)
    {
        //cout<<"hehe "<<I-(i*n)<<endl;
        if((((I-(i*n))>=0)&&(I-(i*n))<n))
        ret.y = i;
    }

    return ret;
}

char ctoi(c pos, char n)
{
    return pos.x + (pos.y*n);
}

