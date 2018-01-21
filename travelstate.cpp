#include "travelstate.h"

TravelState::TravelState(WorldLocation* l, int d) : loc(l), dir(d) {
  // TODO: validate the type and direction
  // TODO: set options based on roadlocation
  
  combatProbability = 30;
  //direction = dirs[dir];

  /*
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
  */

  hasCrossroad = false;
  newDirection = "";

  choices[CONTINUE_OPTION] = "Keep walking.";
  choices[SIT_OPTION] = "Sit and rest.";
  if (hasCrossroad){
    choices[FORK_OPTION] = "Take the " + newDirection + " fork.";
  }
}

void TravelState::printOptions(){
  wprintw(Display::text_win, "You are walking %s\n", dirs[dir].c_str());
  if (hasCrossroad){
    wprintw(Display::text_win, "You see a fork in the road, headed %s\n.", newDirection.c_str());
  }
  wprintw(Display::text_win, "\n");
  for(auto i = choices.begin(); i!=choices.end(); i++){
    wprintw(Display::text_win, "%d. %s\n", i->first, i->second.c_str());
  }
  refresh();
}

TravelState::~TravelState(){};

void TravelState::handleInput(int choice, std::stack<GameState*>& states, Player& p, World& w){
  GameState* nextState = nullptr;

  switch (choice){
    case CONTINUE_OPTION:
      wprintw(Display::text_win, "You continue walking...\n");
      switch (dir){
        case World::North:
          p.moveNorth();
          break;
        case World::South:
          p.moveSouth();
          break;
        case World::East:
          p.moveEast();
          break;
        case World::West:
          p.moveWest();
          break;
      };

      delete states.top();
      states.pop();

      nextState = new TravelState(w.getLocationAt(p.getPos()), dir);
      states.push(nextState);
      break;
    case SIT_OPTION:
      nextState = new IdleState();
      states.push(nextState);
      break;
    case FORK_OPTION:
      if (hasCrossroad) {
        wprintw(Display::text_win, "You take the fork.\n");
        delete states.top();
        states.pop();
        nextState = new TravelState(w.getLocationAt(p.getPos()), 1);
        states.push(nextState);
       }
      else {
        wprintw(Display::text_win, "You take a look around, trying to decide what to do.\n");
      }
      break;
    default:
      wprintw(Display::text_win, "Invalid option.\n");
      break;
  };
}

