GCC = g++
CFLAGS = -std=c++11 -Wall -O3
LDFLAGS = -I. -lncurses -ltinfo
OBJ = obj

OBJFILES = $(addprefix $(OBJ)/,main.o combatstate.o idlestate.o travelstate.o livingentity.o player.o npc.o display.o)

all: main

main: $(OBJFILES)
	$(GCC) -o main $(CFLAGS) $(OBJFILES) $(LDFLAGS)

$(OBJ)/main.o: main.cpp gamestate.h entity.h travelstate.h
	$(GCC) -c $(CFLAGS) main.cpp -o $(OBJ)/main.o $(LDFLAGS)

$(OBJ)/travelstate.o: travelstate.cpp travelstate.h
	$(GCC) -c $(CFLAGS) travelstate.cpp -o $(OBJ)/travelstate.o $(LDFLAGS)

$(OBJ)/combatstate.o: combatstate.cpp travelstate.h
	$(GCC) -c $(CFLAGS) combatstate.cpp -o $(OBJ)/combatstate.o $(LDFLAGS)

$(OBJ)/idlestate.o: idlestate.cpp
	$(GCC) -c $(CFLAGS) idlestate.cpp -o $(OBJ)/idlestate.o $(LDFLAGS)

$(OBJ)/livingentity.o: livingentity.cpp entity.h
	$(GCC) -c $(CFLAGS) livingentity.cpp -o $(OBJ)/livingentity.o $(LDFLAGS)

$(OBJ)/player.o: player.cpp entity.h
	$(GCC) -c $(CFLAGS) player.cpp -o $(OBJ)/player.o $(LDFLAGS)

$(OBJ)/npc.o: npc.cpp entity.h
	$(GCC) -c $(CFLAGS) npc.cpp -o $(OBJ)/npc.o $(LDFLAGS)

$(OBJ)/display.o: display.h display.cpp
	$(GCC) -c $(CFLAGS) display.cpp -o $(OBJ)/display.o $(LDFLAGS)

clean:
	rm -rf $(OBJ)/*.o
	rm main
