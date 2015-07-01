#include "IO_man.h"

int main(){
    
    IO_man io = IO_man("pirates.db");
    io.getPirate(1);
    return 0;
}