#ifndef ZNAK_H_INCLUDED
#define ZNAK_H_INCLUDED

using namespace std;

struct c
{
    char x;
    char y;

    bool operator==(c other);
    bool operator!=(c other);
};

class _ob
{
    bool team;
    bool alive;
    c pos;
    static char n0;
    static char n1;
public:
    _ob();
    char getx();
    char gety();
    void setteam(bool t);

    friend bool check(_ob *tab, char n);
    friend void lm(char *Map, _ob *t0, _ob *t1, char n);
    friend void changer(bool t,c pos,_ob *t0, _ob *t1, char n);
    friend void ini(_ob *t0, _ob *t1,char* Map, char n);
    friend void palive(_ob *t0, _ob *t1, char n);
};

class team
{
    unsigned int w;
    unsigned int l;
    unsigned int d;
    string name;
    bool t;
    char playertype;
public:
    team(bool tea, char playertype=0, string name="");
    ~team();
    void setplayertype(char T);
    string getplayertype();
    bool gett();
    char getpt();
    void StatsFromFile(); //aktualnie puste
    void StatsToFile(); //aktualnie puste

    friend string getplayertype(char T, bool t);
    friend c decide(bool t, team Act, char *Map, char n);
};


#endif // ZNAK_H_INCLUDED
