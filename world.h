#ifndef WORLD_H
#define WORLD_H

#include <ncurses.h>
#include <map>
#include <utility>

#include "display.h"
#include "worldlocation.h"
#include "logger.h"

class World {
  // For efficiency, may want to store pointers instead
  // of actual objects
  std::map<std::pair<int,int>, WorldLocation> cells;

  public:
    World();
    ~World();

    // center (x,y)
    void drawMap(int, int);
    void drawMap(std::pair<int,int>);
};

#endif
