#include "Object.h"
#include <string>
#include <ostream>

using namespace std;

Object::Object(string n, string t, int q){
    type = t;
    name = n;
    quantity = q;
}

string Object::getName(){
    return name;
}

void Object::setName(string n){
    name = n;    
}

string Object::getType(){
    return type;
}

void Object::setType(string t){
    type = t;
}

int Object::getQuantity(){
    return quantity;
}

void Object::setQuantity(int q){
    quantity = q;
}

int Object::getWeight(){
    return weight;
}

void Object::setWeight(int w){
    weight = w;
}
    
bool Object::equals(Object o){
    bool res = false;
    if(name == o.getName()){
        res = true;
    }
    return res;
}

ostream&  Object::toString(ostream& o){
    return o << name << " , " << type << " , " << quantity << " , " << weight <<".\n";
}