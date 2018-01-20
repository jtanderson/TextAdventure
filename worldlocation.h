#ifndef WORLDLOCATION_H
#define WORLDLOCATION_H

#include <ncurses.h>
#include "logger.h"
#include "display.h"

class WorldLocation {
  enum Type{};
  char map_glyph;

  public:
    WorldLocation();
    ~WorldLocation();

    // x, y
    void render(int,int);
};

#endif
