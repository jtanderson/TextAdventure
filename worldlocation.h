#ifndef WORLDLOCATION_H
#define WORLDLOCATION_H

#include <ncurses.h>
#include "logger.h"
#include "display.h"

class WorldLocation {
  private:
  enum Type{};
  const char* map_glyph;

  enum Glyphs {
    player_glyph = 'X'
  };

  public:
    WorldLocation();
    ~WorldLocation();

    // x, y
    void render(int,int);
};

#endif
