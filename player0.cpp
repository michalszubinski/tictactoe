#include <iostream>
#include <cstdlib>
#include <ctime>

#include "znak.h"
#include "players.h"
#include "fx.h"

using namespace std;

c player0(char *Map, char n)
{
    char ran;
    c ret;

    while(true)
    {
        ran = (char)(rand() % (n*n));
        //cout<<(int)ran;
        if(Map[ran]==n-1)
        {
            ret.x = ran % n;
            for(char i=0; i<n;i++)
            {
                //cout<<"hehe "<<ran-(i*n)<<endl;
                if((((ran-(i*n))>=0)&&(ran-(i*n))<n))
                    ret.y = i;
            }
        }
        if((int)Map[ret.y*n + ret.x]==2) return ret;
    }

}
