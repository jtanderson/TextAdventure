#include <stack> // std::stack
#include <stdlib.h>
#include <time.h> // time
#include <ncurses.h>
#include <csignal>
#include <getopt.h>
#include <iostream>
#include <locale.h>

#include "gamestate.h" // GameState
#include "travelstate.h" // TravelState
#include "combatstate.h" // CombatState
#include "entity.h" // Player
#include "display.h" // Display
#include "logger.h" // Logger
#include "world.h"
#include "roadlocation.h"

void interrupt();

void init(int argc, char** argv);

int main(int argc, char** argv){
  // This needs to happen first
  init(argc, argv);

  char input;
  std::stack<GameState*> stateStack;
  int combatRoll;
  CombatState* cs;

  Player pc(20,5,10,5,"Human","Jimbo");
  World world;
  GameState* currentState = nullptr;
  TravelState* t = new TravelState(world.getLocationAt(0,0),World::North);
  stateStack.push(t);

  pc.printInventory();

  while(true){
    world.drawMap(pc.getPos());

    currentState = stateStack.top();

    if (currentState->combatProbability > 0){
      combatRoll = rand() % 100 + 1;
      if (combatRoll < currentState->combatProbability){
        wprintw(Display::text_win, "You get attacked!\n");
        cs = new CombatState();
        stateStack.push(cs);
        currentState = cs;
      }
    }

    currentState->printOptions();

    wrefresh(Display::text_win);

    input = getch();

    wclear(Display::text_win);

    currentState->handleInput(atoi(&input), stateStack, pc, world);
  }

  endwin();
  Logger::close();

  return 0;
}

void interrupt(int i){
  Logger::debug("Closing...\n");
  Logger::close();
  endwin();
  exit(i);
};

void init(int argc, char** argv){
  // For utf-8 glyphs
  setlocale(LC_ALL, "");

  // register the handler to clean up ncurses on close
  signal(SIGINT, interrupt);

  int c;
  bool has_log_option = false;

  while (1) {
    static struct option long_options[] = {
      {"help",     no_argument,       0, 'h'},
      {"log-level", required_argument, 0, 'l'},
      {0, 0, 0, 0}
    };

    /* getopt_long stores the option index here. */
    int option_index = 0;

    c = getopt_long (argc, argv, "?:l:", //"abc:d:f:",
        long_options, &option_index);

    /* Detect the end of the options. */
    if (c == -1){
      break;
    }

    switch (c) {
      case '?':
        printf("TextAdventure!\n");
        printf("Executable usage:\n");
        printf("\t./main [options]\n\n");
        printf("Where [options] is one of the following:\n");
        printf("\t--log-level=[level], -l [level]\n");
        printf("\t\t[level] can be:\n");
        printf("\t\t\tdebug\n");
        printf("\t\t\tinfo\n");
        printf("\t\t\terror (default)\n");
        printf("\t--help, -?\n");
        printf("\t\tPrints this message.\n");
        exit(0);
        break;
      case 'l':
        if (strcmp(optarg,"debug") == 0){
          Logger::init(Logger::DEBUG);
        } else if (strcmp(optarg,"info") == 0){
          Logger::init(Logger::INFO);
        } else {
          printf("Invalid log level: %s\n", optarg);
          exit(1);
        }
        has_log_option = true;
        break;
      default:
        abort ();
    }
  }

  // TODO: make this default to ERROR
  if (!has_log_option){
    Logger::init(Logger::DEBUG);
  }

  Logger::debug("Loading...\n");

  // initialize UI
  Display::init();

  // Seed the rng
  srand(time(0));
}


