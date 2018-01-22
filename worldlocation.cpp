#include "worldlocation.h"

WorldLocation::WorldLocation(int x, int y){
  coords = std::make_pair(x,y);
}

WorldLocation::~WorldLocation(){ }

void WorldLocation::render(int x, int y){
  //Logger::debug("Drawing at map window cell (%d, %d)\n",x,y);
  //const char* t = "\u0394";
  mvwaddstr(Display::map_win, x, y, map_glyph);
}

std::pair<int,int> WorldLocation::getCoords(){
  return coords;
};

