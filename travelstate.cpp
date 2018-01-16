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
  std::cout << "You are walking " << direction << std::endl;
  if (hasCrossroad){
    std::cout << "You see a fork in the road, headed " << newDirection << std::endl;
  }
  for(auto i = choices.begin(); i!=choices.end(); i++){
    std::cout << i->first << ". " << i->second << std::endl;
  }
}

TravelState::~TravelState(){};

void TravelState::handleInput(std::string in, std::stack<GameState*>& states, Player& p){
  int choice = std::stoi(in);
  GameState* nextState = nullptr;

  switch (choice){
    case CONTINUE_OPTION:
      std::cout << "\nYou continue walking...\n";
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
      std::cout << "\nYou take the fork...\n";
      delete states.top();
      states.pop();
      nextState = new TravelState(newDirection);
      states.push(nextState);
      break;
    default:
      std::cout << "Invalid option.\n";
      break;
  };
}

