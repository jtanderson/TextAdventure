#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <map>
#include <stack>
#include <ncurses.h>
#include <stdlib.h>

//#include "player.h" // Player
class Player;
#include "display.h"
//#include "world.h"
class World;

class GameState {
  protected:
    std::map<int, std::string> choices;

  public:
    virtual ~GameState(){};
    double combatProbability = 0;
    virtual void printOptions() = 0;
    virtual void handleInput(int, std::stack<GameState*>&, Player&, World&) = 0;
};

#endif
