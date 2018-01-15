GCC = g++
CFLAGS = -std=c++11 -Wall -O3
LDFLAGS = -I.
OBJ = obj

all: main

main: $(addprefix $(OBJ)/,main.o combatstate.o idlestate.o travelstate.o livingentity.o player.o npc.o)
	$(GCC) -o main $(CFLAGS) $(LDFLAGS) $(addprefix $(OBJ)/,main.o combatstate.o idlestate.o travelstate.o livingentity.o player.o npc.o)

$(OBJ)/main.o: main.cpp gamestate.h entity.h travelstate.h
	$(GCC) -c $(CFLAGS) $(LDFLAGS) main.cpp -o $(OBJ)/main.o

$(OBJ)/travelstate.o: travelstate.cpp travelstate.h
	$(GCC) -c $(CFLAGS) $(LDFLAGS) travelstate.cpp -o $(OBJ)/travelstate.o

$(OBJ)/combatstate.o: combatstate.cpp travelstate.h
	$(GCC) -c $(CFLAGS) $(LDFLAGS) combatstate.cpp -o $(OBJ)/combatstate.o

$(OBJ)/idlestate.o: idlestate.cpp
	$(GCC) -c $(CFLAGS) $(LDFLAGS) idlestate.cpp -o $(OBJ)/idlestate.o

$(OBJ)/livingentity.o: livingentity.cpp entity.h
	$(GCC) -c $(CFLAGS) $(LDFLAGS) livingentity.cpp -o $(OBJ)/livingentity.o

$(OBJ)/player.o: player.cpp entity.h
	$(GCC) -c $(CFLAGS) $(LDFLAGS) player.cpp -o $(OBJ)/player.o

$(OBJ)/npc.o: npc.cpp entity.h
	$(GCC) -c $(CFLAGS) $(LDFLAGS) npc.cpp -o $(OBJ)/npc.o

clean:
	rm -rf $(OBJ)/*.o
	rm main
