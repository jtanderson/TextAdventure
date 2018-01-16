#include <iostream>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "gamestate.h"
#include "travelstate.h"
#include "idlestate.h"
#include "combatstate.h"
#include "entity.h" // Player

int main(){
  char input;
  std::stack<GameState*> stateStack;
  Player pc(20,5,10,5,"Human","Jimbo");
  int combatRoll;
  CombatState* cs;

  initscr();
  noecho();

  srand(time(0));

  clear();

  GameState* currentState = nullptr;
  TravelState* t = new TravelState("North");
  stateStack.push(t);

  while(true){
    currentState = stateStack.top();

    if (currentState->combatProbability > 0){
      combatRoll = rand() % 100 + 1;
      if (combatRoll < currentState->combatProbability){
        printw("You get attacked!\n");
        cs = new CombatState();
        stateStack.push(cs);
        currentState = cs;
      }
    }

    currentState->printOptions();
    refresh();
    input = getch();
    clear();
    //printw("You pressed %c", input);
    currentState->handleInput(atoi(&input), stateStack, pc);
  }

  endwin();

  return 0;
}
