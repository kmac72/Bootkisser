#include <stdlib.h>
#include "Pirate.h"

using namespace std;

Pirate* currentPirate;

//reads in pirate info from config and assigns to currentPirate object
bool loadPirate(string name) {
    
    string search;
    ifstream in("pirate_config.txt");
    int foundPirate = 0;
    
    while(getline(in, search)) {
        
        if(foundPirate == 1) {
            
            foundPirate++;
            
            //parse the pirate config string
            string delimiter = " , ";
            
            string role = search.substr(0, search.find(delimiter));
            search = search.substr(search.find(delimiter) + 3, search.find("#"));
        
            string ship = search.substr(0, search.find(delimiter));
            search = search.substr(search.find(delimiter) + 3, search.find("#"));
            
            string doubloon = search.substr(0, search.find("#"));
            
            cout << "Loaded Pirate: " << name << ", ";
            cout << role << ", " << ship << ", " << doubloon << " doubloons" << endl;
            
            //create loaded pirate object
            currentPirate = new Pirate(name, atoi(role.c_str()), ship, atoi(doubloon.c_str()));
            
            return true;
        }
        
        if(search == name) {
            
            foundPirate++;
        }
    }
 
    return false;
}

int main() {
    
    string inName;
    int option;
    
    while(true) {
    
        cout << "================================================================" << endl;
        cout << "                  Welcome to Pirates!" << endl;
        cout << "================================================================" << endl;
    
        cout << "Enter your existing pirates name or 'new' to begin your journey." << endl;
        cin >> inName;
        
        //create new pirate with default constructor and assign to currentPirate
        if(inName == "new") {
            
            cout << "Welcome aboard!" << endl;
            cout << "Enter your new pirates name: ";
            
            cin >> inName;
            
            currentPirate = new Pirate(inName);
            currentPirate->addPirate();
            
        }
        
        if(!loadPirate(inName)) {
            
            cout << "Pirate not found..." << endl;
        } else {
            
            bool quit = false;
            
            while(true) {
                
                cout << endl << "Pirate Options: " << endl;
                cout << "1 - Swab the Deck (10 seconds, 30% success)" << endl;
                cout << "2 - Gamble With Another Pirate" << endl;
                cout << "3 - TBT" << endl;
                cout << "4 - View Pirate Info" << endl;
                cout << "5 - Save and Exit" << endl;
                
                cout << "Enter number: ";
                cin >> option;
                cout << endl;
                
                switch(option) {
                    case 1: {
                        cout << "Swabbing Deck..." << endl;
                        currentPirate->swabDeck();
                        break;
                    }
                    case 2: {
                        string newName;
                        cout << "Who would you like to gamble with?" << endl;
                        cin >> newName;
                        Pirate* tempPirate = currentPirate;
                        loadPirate(newName);
                        if(tempPirate->gamble(currentPirate))
                            cout << "Won doubloons from " << currentPirate->getName() << endl;
                        else
                            cout << "Lost doubloons from " << currentPirate->getName() << endl;
                            
                        currentPirate->savePirate();
                        currentPirate = tempPirate;
                        delete tempPirate;
                        break;
                    }
                    case 3: 
                        break;
                    case 4: {
                        currentPirate->printInfo();
                        break;
                    }
                    case 5: {
                        currentPirate->savePirate();
                        quit = true;
                        break;
                    }
                }
                
                if(quit)
                    break;
            }
        }
    }
    
    return 0;
}