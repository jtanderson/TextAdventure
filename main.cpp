#include <stack> // std::stack
#include <stdlib.h>
#include <time.h> // time
#include <ncurses.h>
#include <csignal>

#include "gamestate.h" // GameState
#include "travelstate.h" // TravelState
#include "combatstate.h" // CombatState
#include "entity.h" // Player
#include "display.h" // Display
#include "logger.h" // Logger

void interrupt(int i){
  Logger::debug("Closing...\n");
  Logger::close();
  endwin();
  exit(i);
};

int main(int argc, char** argv){
 
  // Needs to come first in case any ctors use logging
  Logger::init(Logger::DEBUG);
  Logger::debug("Loading...\n");

  char input;
  std::stack<GameState*> stateStack;
  int combatRoll;
  CombatState* cs;

  Player pc(20,5,10,5,"Human","Jimbo");

  signal(SIGINT, interrupt);

  Display::init();
  srand(time(0));

  wrefresh(Display::text_win);

  GameState* currentState = nullptr;
  TravelState* t = new TravelState("North");
  stateStack.push(t);

  pc.printInventory();

  while(true){
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

  // TODO: also do this on sigint
  endwin();
  Logger::close();

  return 0;
}
