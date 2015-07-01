all:

	g++ main.cpp Pirate.cpp Ship.cpp Object.cpp setup.h IO_man.cpp -l sqlite3 -o pirates_game
	
clean:

	rm *.o
