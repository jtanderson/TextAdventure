#ifndef TRAVELSTATE_H
#define TRAVELSTATE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <list>
#include "gamestate.h"
#include "idlestate.h"

class TravelState : public GameState {
  private:
    // Current direction of travel
    std::string direction;

    // Denotes if there is a fork
    bool hasCrossroad;

    // The direction of the crossroad
    std::string newDirection;

    // Choice constants
    enum Choices{
      CONTINUE_OPTION = 1,
      SIT_OPTION      = 2,
      FORK_OPTION     = 3
    };

  public:
    TravelState(std::string);
    ~TravelState();

    void printOptions() override;

    void handleInput(int, std::stack<GameState*>&, Player&) override;
};

#endif
