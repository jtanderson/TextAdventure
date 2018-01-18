#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <map>
#include <stack>
#include <ncurses.h>
#include "player.h" // Player
#include "display.h"

class GameState {
  protected:
    std::map<int, std::string> choices;

  public:
    virtual ~GameState(){};
    double combatProbability = 0;
    virtual void printOptions() = 0;
    virtual void handleInput(int, std::stack<GameState*>&, Player&) = 0;
};

#endif
