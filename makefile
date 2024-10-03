CC=g++ -std=c++11 -g
EXE_FILE = all 
OBJECTS = main.o game.o room.o event.o gold.o wumpus.o bats.o stalactites.o

$(EXE_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE_FILE)

main.o: main.cpp	
	$(CC) -c main.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

room.o: room.cpp room.h
	$(CC) -c room.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp

gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp

bats.o: bats.cpp bats.h
	$(CC) -c bats.cpp

stalactites.o: stalactites.cpp stalactites.h 
	$(CC) -c stalactites.cpp


clean:
	rm -f *.o $(EXE_FILE)