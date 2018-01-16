#include "idlestate.h"

IdleState::IdleState(){
  choices[CONTINUE_OPTION] = "Keep sitting.";
  choices[LEAVE_OPTION] = "Get up and keep walking.";
}

void IdleState::printOptions(){
  printw("You are sitting at the side of the road\n");
  for(auto i=choices.begin(); i!=choices.end(); i++){
    printw("%d. %s\n", i->first, i->second.c_str());
  }
}

IdleState::~IdleState(){}

void IdleState::handleInput(int choice, std::stack<GameState*>& states, Player& p){
  GameState* next = nullptr;
  GameState* old = nullptr;

  switch(choice){
    case CONTINUE_OPTION:
      old = states.top();
      states.pop();
      delete old;
      p.heal(5);
      printw("You recover 5 hp...\n");
      next = new IdleState();
      states.push(next);
      break;
    case LEAVE_OPTION:
      old = states.top();
      states.pop();
      delete old;
      break;
    default:
      break;
  }
}
