#include "travelstate.h"

TravelState::TravelState(WorldLocation* l, int d) : loc(l), dir(d) {
  // TODO: validate the type and direction
  // TODO: set options based on roadlocation
  
  combatProbability = 20;

  direction = Util::getDirName(dir);

  hasCrossroad = false;
  newDirection = "";

  //choices[CONTINUE_OPTION] = "Keep walking " + direction + ".";
  choices[SIT_OPTION] = "Sit and rest.";

  loc->addOptions(choices);
}

void TravelState::printOptions(){
  wprintw(Display::text_win, "You are walking %s\n", direction.c_str());

  wprintw(Display::text_win, "\n");
  for(auto i = choices.begin(); i!=choices.end(); i++){
    wprintw(Display::text_win, "%c. %s\n", i->first, i->second.c_str());
  }
  refresh();
}

TravelState::~TravelState(){};

void TravelState::handleInput(int choice, std::stack<GameState*>& states, Player& p, World& w){
  GameState* nextState = nullptr;

  switch (choice){
    case SIT_OPTION:
      nextState = new IdleState();
      states.push(nextState);
      break;
    default:
      // See if the location can handle it
      loc->handleInput(choice, states, p, w);
      break;
  };
}

