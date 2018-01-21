#ifndef TRAVELSTATE_H
#define TRAVELSTATE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <map>
#include "gamestate.h"
#include "idlestate.h"
#include "world.h"
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

    std::map<int, std::string> dirs = {
      {World::North, "North"},
      {World::South, "South"},
      {World::East,  "East"},
      {World::West,  "West"}
    };

    // Choice constants
    enum Choices{
      CONTINUE_OPTION = 1,
      SIT_OPTION      = 2,
      FORK_OPTION     = 3
    };

  public:
    TravelState(WorldLocation*, int);
    ~TravelState();

    void printOptions() override;

    void handleInput(int, std::stack<GameState*>&, Player&, World&) override;
};

#endif
