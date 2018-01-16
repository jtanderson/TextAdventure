#include "idlestate.h"

IdleState::IdleState(){
  choices[CONTINUE_OPTION] = "Keep sitting.";
  choices[LEAVE_OPTION] = "Get up and keep walking.";
}

void IdleState::printOptions(){
  std::cout << "You are sitting at the side of the road\n";
  for(auto i=choices.begin(); i!=choices.end(); i++){
    std::cout << i->first << ". " << i->second << std::endl;
  }
}

IdleState::~IdleState(){}

void IdleState::handleInput(std::string in, std::stack<GameState*>& states, Player& p){
  GameState* next = nullptr;
  GameState* old = nullptr;
  int choice = stoi(in);

  switch(choice){
    case CONTINUE_OPTION:
      old = states.top();
      states.pop();
      delete old;
      p.heal(5);
      std::cout << "You recover 5 hp...\n";
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
