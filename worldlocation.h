#ifndef WORLDLOCATION_H
#define WORLDLOCATION_H

#include <ncurses.h>
#include <map>

#include "logger.h"
#include "display.h"

class WorldLocation {
  protected:
    enum Type{};

    enum Glyph {
      player_glyph = 'X'
    };

    const char* map_glyph;
    std::pair<int,int> coords;

  public:
    WorldLocation(int, int);
    WorldLocation(int, int, WorldLocation*);
    //WorldLocation(const char*);

    std::pair<int,int> getCoords();
    virtual ~WorldLocation();
    // x, y
    virtual void render(int,int);

    // takes direction
    virtual WorldLocation* connect(int) = 0;

    virtual void addOptions(std::map<int,std::string>&) = 0;
};

#endif
