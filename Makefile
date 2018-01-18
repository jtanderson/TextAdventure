.PHONY: all

GCC = g++
CFLAGS = -std=c++11 -Wall -O3
LDFLAGS = -I. -lncurses -ltinfo
OBJDIR = obj

CLASSES = combatstate idlestate travelstate livingentity player npc display inventory item
OBJECTS = $(addsuffix .o, $(CLASSES))
OBJFILES = $(addprefix $(OBJDIR)/, $(OBJECTS))

all: main

main: $(OBJDIR)/main.o $(OBJFILES)
	$(GCC) -o main $(CFLAGS) $(OBJDIR)/main.o $(OBJFILES) $(LDFLAGS)

$(OBJDIR)/main.o: main.cpp gamestate.h entity.h travelstate.h
	$(GCC) -c $(CFLAGS) main.cpp -o $(OBJDIR)/main.o $(LDFLAGS)

.SECONDEXPANSION:
$(OBJFILES): %.o: $$(notdir %.cpp %.h)
	$(GCC) -c $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(OBJDIR)/*.o
	rm main
