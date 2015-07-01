#include <stdio.h>
#include <sqlite3.h> 
#include <stdlib.h>
#include <string>
#include <sstream>
#include "IO_man.h"

using namespace std;

string toString(int value) {
   
   std::ostringstream os ;
   os << value ;
   return os.str() ;
 }

int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

IO_man::IO_man(string dbn) {
   dbname = dbn;
}

void IO_man::getPirate(int id_p){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   string sql;
   const char* data = "Callback function called";
   
   try{
      rc = sqlite3_open(dbname.c_str(), &db);
      string newStr = toString(id_p);
      sql = "SELECT * FROM Pirates WHERE id_player=" + newStr  +";"; 
      rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
      if( rc != SQLITE_OK ){
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
      }else{
         cout << data << endl;
         //fprintf(stdout, data);
      }
      sqlite3_close(db);
   }
   catch (exception& e)  {
      fprintf(stderr,  "Can't open database: %s\n", e.what());
   }
   
}

void IO_man::addPirate(Pirate newPirate){
   
}





