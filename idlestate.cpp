#include "idlestate.h"

IdleState::IdleState(){
  choices[CONTINUE_OPTION] = "Keep sitting.";
  choices[LEAVE_OPTION] = "Get up and keep walking.";
}

void IdleState::printOptions(){
  wprintw(Display::text_win, "You are sitting at the side of the road\n");
  for(auto i=choices.begin(); i!=choices.end(); i++){
    wprintw(Display::text_win, "%c. %s\n", i->first, i->second.c_str());
  }
}

IdleState::~IdleState(){}

void IdleState::handleInput(int choice, std::stack<GameState*>& states, Player& p, World& w){
  GameState* next = nullptr;
  GameState* old = nullptr;

  switch(choice){
    case CONTINUE_OPTION:
      old = states.top();
      states.pop();
      delete old;
      p.heal(5);
      wprintw(Display::text_win, "You recover 5 hp...\n");
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
