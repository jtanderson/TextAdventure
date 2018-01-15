#ifndef GAMESTATE_H
#define GAMESTATE_H

#include<map>
#include<stack>
#include "entity.h" // Player

class GameState {
  protected:
    std::map<int, std::string> choices;

  public:
    virtual ~GameState(){};
    double combatProbability = 0;
    virtual void printOptions() = 0;
    virtual void handleInput(std::string, std::stack<GameState*>&, Player&) = 0;
};

#endif
