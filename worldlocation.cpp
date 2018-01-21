#include "worldlocation.h"

WorldLocation::WorldLocation(int x, int y){
  coords = std::make_pair(x,y);
  //map_glyph = L'\u04c1';
  //map_glyph = ACS_PLMINUS;
  //map_glyph = '-';
  //map_glyph = "\u2591"; // light block
  //map_glyph = "\u2501"; // road
}

//WorldLocation::WorldLocation(const char* g) : map_glyph(g) { }

WorldLocation::~WorldLocation(){
}

void WorldLocation::render(int x, int y){
  //Logger::debug("Drawing at map window cell (%d, %d)\n",x,y);
  //const char* t = "\u0394";
  mvwaddstr(Display::map_win, x, y, map_glyph);
}

std::pair<int,int> WorldLocation::getCoords(){
  return coords;
};

