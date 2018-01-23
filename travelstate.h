#ifndef TRAVELSTATE_H
#define TRAVELSTATE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <map>
#include "gamestate.h"
#include "idlestate.h"
//#include "world.h"
class World;
#include "worldlocation.h"
#include "roadlocation.h"

class TravelState : public GameState {
  private:
    // Current direction of travel
    std::string direction;
    WorldLocation* loc;
    int dir;

    // Denotes if there is a fork
    bool hasCrossroad = false;

    // The direction of the crossroad
    std::string newDirection = "";

    // Choice constants
    enum Choices{
      SIT_OPTION      = 1,
      CONTINUE_OPTION = 2,
      FORK_OPTION     = 3
    };

  public:
    TravelState(WorldLocation*, int);
    ~TravelState();

    void printOptions() override;

    void handleInput(int, std::stack<GameState*>&, Player&, World&) override;
};

#endif
