#include "Pirate.h"

#define MAX_BELONGINGS 10

using namespace std;

//==========================Constructors=========================

Pirate::Pirate(string n) {
    
    name = n;
    role = 1;
    ship = "no ship";
    doubloon = 100;
}

Pirate::Pirate(string n, int r, string s, int dou) {
    
    name = n;
    role = r;
    ship = s;
    doubloon = dou;
}

//=========================File IO/ Console IO=============================

//appends new pirate entry to end of config file
void Pirate::addPirate() {
    
    ofstream out;
    out.open("pirate_config.txt", ios::app);
    
    out << name << endl;
    out << role << " , " << ship << " , " << doubloon << "#" << endl;
    
    out.close();
}

//rewrites config file and replaces old pirate info with new info
void Pirate::savePirate() {
    
    ofstream out;
    out.open("temp_config.txt");
    
    string search;
    ifstream in("pirate_config.txt");
    
    int foundPirate = 0;
    
    //search line by line through config for pirate name
    while(getline(in, search)) {
        
        //write old config file into temp one for all lines except new pirate info
        if(foundPirate != 1)
            out << search << endl;
        else
            foundPirate++;
        
        //if found, overwrite the pirates info line
        if((search == name) && (foundPirate == 0)) {

            foundPirate++;
            out << role << " , " << ship << " , " << doubloon << "#" << endl;
            
        }
    }
    
    out.close();
    in.close();
    
    remove("pirate_config.txt");
    rename("temp_config.txt", "pirate_config.txt");
}

void Pirate::printInfo(){
    
    cout << "=========================" << endl;
    cout << "Name: " << name << endl;
    cout << "Role: " << role << endl;
    cout << "Ship: " << ship << endl;
    cout << "Doubloons: " << doubloon << endl;
    cout << "=========================" << endl;
}

//=========================Pirate Actions=======================

//task takes 10 seconds and 1/3 change of recieving 10 doubloons
bool Pirate::swabDeck() {
    
    sleep(10);
    int chance = rand() % 4;
    if(chance != 0) {
        doubloon += 10;
        cout << "Earned 10 doubloons!" << endl;
        return true;
    }
    else {
        cout << "Your work went unnoticed." << endl;
        return false;
    }
}

bool Pirate::gamble(Pirate* p) {
    
    int chance = rand() % 2;
    if(chance == 0) {
        
        //take 100 from loser and give to winner
        if(p->getDoubloon() > 99) {
            doubloon += 100;
            p->setDoubloon(p->getDoubloon() - 100);
        } else {
            doubloon += p->getDoubloon();
            p->setDoubloon(0);
        }
        
        return true;
    } else {
    
        //take 100 from loser and give to winner
        if(doubloon > 99) {
            doubloon -= 100;
            p->setDoubloon(p->getDoubloon() + 100);
        } else {
            p->setDoubloon(doubloon);
            doubloon = 0;
        }        
        
        return false;
    }
}

//=========================Getters/Setters=======================

string Pirate::getName() {
    
    return name;
}

int Pirate::getRole() {
    
    return role;
}

void Pirate::setRole(int r) {
    
    role = r;
}

string Pirate::getShip() {
    
    return ship;
}

void Pirate::setShip(string s_name) {
    
    ship = s_name;
}

int Pirate::getDoubloon() {
    
    return doubloon;
}

void Pirate::setDoubloon(int dou) {
    
    doubloon = dou;
}

vector<Object> Pirate::getBelongings() {
    
    return belongings;
}

bool Pirate::addBelongings(Object thing) {
    
    if(belongings.size() < MAX_BELONGINGS) {
        
        belongings.push_back(thing);
        return true;
    }
    else
        return false;
}

bool Pirate::deleteBelongings(string obj) {
    
    return true;
}

bool Pirate::replaceBelongings(string name ,Object obj) {
    
    return true;
}