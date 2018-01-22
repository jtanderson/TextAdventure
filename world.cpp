#include "world.h"

World::World(){
  cells[std::make_pair(0,0)] = new RoadLocation(0,0,RoadLocation::NorthSouth);
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

  WorldLocation* currentLoc = getLocationAt(x,y);

  Logger::debug("drawing centered at (%d,%d)\n",x,y);
  wclear(Display::map_win);

  // Generate cells adjacent to (x,y)
  //
  auto test = cells.find(std::make_pair(x-1,y));
  if (test == cells.end()){
    //Logger::debug("generating (%d,%d)\n",j,i);
    cells[std::make_pair(x-1,y)] = currentLoc->connect(West);
  }

  test = cells.find(std::make_pair(x,y+1));
  if (test == cells.end()){
    //Logger::debug("generating (%d,%d)\n",j,i);
    cells[std::make_pair(x,y+1)] = currentLoc->connect(North);
  }

  test = cells.find(std::make_pair(x,y-1));
  if (test == cells.end()){
    //Logger::debug("generating (%d,%d)\n",j,i);
    cells[std::make_pair(x,y-1)] = currentLoc->connect(South);
  }

  test = cells.find(std::make_pair(x+1,y));
  if (test == cells.end()){
    //Logger::debug("generating (%d,%d)\n",j,i);
    cells[std::make_pair(x+1,y)] = currentLoc->connect(East);
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
        mvwaddstr(Display::map_win, row, col, "\u25A3");
      } else if(search != cells.end()){
        Logger::debug("drawing cell (%d, %d)\n", j, i);
        search->second->render(row, col);
      }
      col++;
    }
    row++;
  }
  wrefresh(Display::map_win);
}

WorldLocation* World::getLocationAt(std::pair<int,int> l){
  return getLocationAt(l.first, l.second);
}

WorldLocation* World::getLocationAt(int x, int y){
  auto search = cells.find(std::make_pair(x,y));
  if(search != cells.end()){
    return search->second;
  } else {
    // Since we only move one at a time, and all adjacent
    // get generated, should be fine for now...
    throw "Location invalid!";
  }
};

std::map<int, std::string> World::DirNames = {
  {World::North, "North"},
  {World::South, "South"},
  {World::East,  "East"},
  {World::West,  "West"}
};

std::string World::getDirName(int d){
  auto search = DirNames.find(d);
  if (search != DirNames.end()){
    return search->second;
  } else {
    return "";
  }
};
