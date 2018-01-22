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
      South = -1,
      East  = 2,
      West  = -2
    };

    static std::map<int, std::string> DirNames;

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
    static std::string getDirName(int);
};

#endif
