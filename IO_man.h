#include <string>
#include "Pirate.h"

using namespace std;

class IO_man {
   string dbname;
   
   public:
      
      IO_man(string dbn);
      void getPirate(int id_p);
      void addPirate(Pirate newPirate);
};