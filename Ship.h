#include <vector>
#include <string>
#include "Pirate.h"

using namespace std;

class Ship {
    
    string name;
    int limit_weight;
    int weight; 
    int damage;
    int gold;
    int food;
    vector<Object> cargo;
    vector<Pirate> pirates;
    vector<Object> weapons;
    
    public:
    
    Ship(string n);
    
    
};