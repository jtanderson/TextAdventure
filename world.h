#ifndef WORLD_H
#define WORLD_H

#include <ncurses.h>
#include <map>
#include <utility>

#include "display.h"
#include "worldlocation.h"
#include "roadlocation.h"
#include "logger.h"

class World {
  public:
    enum Direction {
      North = 1,
      South = 2,
      East  = 3,
      West  = 4
    };
  private:
    std::map<std::pair<int,int>, WorldLocation*> cells;

  public:
    World();
    ~World();

    // center (x,y)
    void drawMap(int, int);
    void drawMap(std::pair<int,int>);
    WorldLocation* getLocationAt(std::pair<int, int>);
    WorldLocation* getLocationAt(int, int);
};

#endif
