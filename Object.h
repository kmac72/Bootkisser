#include <string>
#include <ostream>

using namespace std;

class Object{
    
    string type;
    string name;
    int quantity;
    int weight;
    
    public:
    
    Object(string n, string t, int q);
    string getName();
    void setName(string n);
    string getType();
    void setType(string t);
    int getQuantity();
    void setQuantity(int q);
    int getWeight();
    void setWeight(int w);
    
    bool equals(Object o);
    ostream& toString(ostream& o);
};