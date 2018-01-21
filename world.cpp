#include "world.h"

World::World(){
  cells[std::make_pair(0,0)] = WorldLocation();
}

World::~World(){
}

void World::drawMap(std::pair<int,int> loc){
  drawMap(loc.first, loc.second);
}

// Input: center world location
void World::drawMap(int x, int y){
  int mapw, maph;
  getmaxyx(Display::map_win, maph, mapw);

  int left = x - mapw/2;
  int top = y + maph/2;

  // Generate cells adjacent to (x,y)
  for(int i=y-1; i<y+2; i++){
    for(int j=x-1; j<x+2; j++){
      auto test = cells.find(std::make_pair(j,i));
      if (test == cells.end()){
        cells[std::make_pair(j,i)] = WorldLocation();
      }
    }
  }

  //Logger::debug("checking from cell (%d, %d) to (%d, %d)\n", x, y, x+width, y+height);
  int row = 0;
  int col = 0;
  // Draw cells
  for(int i = top; i > y - maph; i--){
    col = 0;
    for(int j = left; j < left + mapw; j++){
      //Logger::debug("checking cell (%d, %d)\n", i, j);
      auto search = cells.find(std::make_pair(j,i));
      if(i == y && j == x){
        mvwaddch(Display::map_win, row, col, 'X');
      } else if(search != cells.end()){
        Logger::debug("drawing cell (%d, %d)\n", j, i);
        search->second.render(row, col);
      }
      col++;
    }
    row++;
  }
  wrefresh(Display::map_win);
}

