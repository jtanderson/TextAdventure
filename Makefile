.PHONY: all

GCC = g++
CFLAGS = -std=c++11 -Wall -O3
LDFLAGS = -I. -lncurses
OBJDIR = obj

UNAME = $(shell uname -s)
ifeq ($(UNAME),Linux)
	LDFLAGS += -ltinfo
endif

ifeq ($(UNAME),Darwin)
	#nothing extra yet
endif

CLASSES = entity combatstate idlestate travelstate livingentity player npc display inventory item logger util world worldlocation
OBJECTS = $(addsuffix .o, $(CLASSES))
OBJFILES = $(addprefix $(OBJDIR)/, $(OBJECTS))

all: main

main: $(OBJDIR)/main.o $(OBJFILES)
	$(GCC) -o main $(CFLAGS) $(OBJDIR)/main.o $(OBJFILES) $(LDFLAGS)

$(OBJDIR)/main.o: main.cpp
	$(GCC) -c $(CFLAGS) main.cpp -o $(OBJDIR)/main.o

.SECONDEXPANSION:
$(OBJFILES): %.o: $$(notdir %.cpp %.h)
	$(GCC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o
	rm main
