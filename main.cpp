#include <iostream>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include "gamestate.h"
#include "travelstate.h"
#include "idlestate.h"
#include "combatstate.h"
#include "entity.h" // Player

int main(){
  std::string input;
  std::stack<GameState*> stateStack;
  Player pc(20,5,10,5,"Human","Jimbo");
  int combatRoll;
  CombatState* cs;

  srand(time(0));

  system("clear");

  GameState* currentState = nullptr;
  TravelState* t = new TravelState("North");
  stateStack.push(t);

  while(true){
    currentState = stateStack.top();

    if (currentState->combatProbability > 0){
      combatRoll = rand() % 100 + 1;
      if (combatRoll < currentState->combatProbability){
        std::cout << "You get attacked!\n";
        cs = new CombatState();
        stateStack.push(cs);
        currentState = cs;
      }
    }

    currentState->printOptions();
    std::getline(std::cin, input);
    system("clear");
    currentState->handleInput(input, stateStack, pc);
  }
}
