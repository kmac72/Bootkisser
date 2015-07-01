#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Object.h"

using namespace std;

class Pirate {
    
    string name;
    int role;
    string ship;
    int doubloon;
    vector<Object>belongings;
    
    public:
    
    Pirate(string n);
    Pirate(string n, int r, string s, int dou);
    
    void addPirate();
    void savePirate();    
    void printInfo();
    
    bool swabDeck();
    bool gamble(Pirate* p);
    
    string getName();
    void setName(string n);
    int getRole();
    void setRole(int r);
    string getShip();
    void setShip(string s_name);
    int getDoubloon();
    void setDoubloon(int dou);
    vector<Object> getBelongings();
    bool addBelongings(Object thing);
    bool deleteBelongings(string obj);
    bool replaceBelongings(string name ,Object obj);
};