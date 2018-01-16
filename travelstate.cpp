#include "travelstate.h"

TravelState::TravelState(std::string dir){
  combatProbability = 30;
  direction = dir;

  srand(time(0));
  if ( rand()%10 + 1 > 7 ){ // 30% chance
    hasCrossroad = true;
    std::list<std::string> dirs;
    if( direction != "South" )
      dirs.push_front("North");
    if( direction != "North" )
      dirs.push_front("South");
    if( direction != "West" )
      dirs.push_front("East");
    if( direction != "East" )
      dirs.push_front("West");

    dirs.remove(direction);
    newDirection = *std::next(dirs.begin(), rand()%dirs.size());
  } else {
    hasCrossroad = false;
  }

  choices[CONTINUE_OPTION] = "Keep walking.";
  choices[SIT_OPTION] = "Sit and rest.";
  if (hasCrossroad){
    choices[FORK_OPTION] = "Take the " + newDirection + " fork.";
  }
}

void TravelState::printOptions(){
  printw("You are walking %s\n", direction.c_str());
  if (hasCrossroad){
    printw("You see a fork in the road, headed %s\n.", newDirection.c_str());
  }
  printw("\n");
  for(auto i = choices.begin(); i!=choices.end(); i++){
    printw("%d. %s\n", i->first, i->second.c_str());
  }
  refresh();
}

TravelState::~TravelState(){};

void TravelState::handleInput(int choice, std::stack<GameState*>& states, Player& p){
  GameState* nextState = nullptr;

  switch (choice){
    case CONTINUE_OPTION:
      printw("You continue walking...\n");
      delete states.top();
      states.pop();

      nextState = new TravelState(direction);
      states.push(nextState);
      break;
    case SIT_OPTION:
      nextState = new IdleState();
      states.push(nextState);
      break;
    case FORK_OPTION:
      printw("You take the fork.\n");
      delete states.top();
      states.pop();
      nextState = new TravelState(newDirection);
      states.push(nextState);
      break;
    default:
      printw("Invalid option.\n");
      break;
  };
}

