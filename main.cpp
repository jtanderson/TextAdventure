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

void interrupt(int i){
  Logger::debug("Closing...\n");
  Logger::close();
  endwin();
  exit(i);
};

int main(int argc, char** argv){
  // TODO: use gnu getopt to parse the args

  setlocale(LC_ALL, "");

  // Needs to come first in case any ctors use logging
  Logger::init(Logger::DEBUG);
  Logger::debug("Loading...\n");

  char input;
  std::stack<GameState*> stateStack;
  int combatRoll;
  CombatState* cs;

  Player pc(20,5,10,5,"Human","Jimbo");
  World world;

  signal(SIGINT, interrupt);

  Display::init();
  srand(time(0));

  //mvwaddstr(Display::text_win, 10, 10, "\u2605");
  //wrefresh(Display::text_win);
  //getch();

  GameState* currentState = nullptr;
  TravelState* t = new TravelState("North");
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

    currentState->handleInput(atoi(&input), stateStack, pc);
  }

  endwin();
  Logger::close();

  return 0;
}
