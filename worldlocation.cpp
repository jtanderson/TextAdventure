#include "worldlocation.h"

WorldLocation::WorldLocation(){
  //map_glyph = L'\u04c1';
  //map_glyph = ACS_PLMINUS;
  map_glyph = 'x';
}

WorldLocation::~WorldLocation(){
}

void WorldLocation::render(int x, int y){
  //Logger::debug("Drawing at map window cell (%d, %d)\n",x,y);
  mvwaddch(Display::map_win, x, y, map_glyph);
}
