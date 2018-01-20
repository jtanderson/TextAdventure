#ifndef WORLD_H
#define WORLD_H

#include <ncurses.h>
#include <map>
#include <utility>

#include "display.h"
#include "worldlocation.h"
#include "logger.h"

class World {
  std::map<std::pair<int,int>, WorldLocation> cells;

  public:
    World();
    ~World();

    // center (x,y)
    void drawMap(int, int);
};

#endif
