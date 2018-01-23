#include "wildernesslocation.h"

WildernessLocation::WildernessLocation(int x, int y) : WorldLocation(x,y) {
  map_glyph = "\u2591";
};

WildernessLocation::WildernessLocation(std::pair<int,int> c) : WorldLocation(c.first,c.second) {
  map_glyph = "\u2591";
};

WildernessLocation::~WildernessLocation(){};

WorldLocation* WildernessLocation::connect(int side){
  return new WildernessLocation(Util::getSide(coords, side));
};

void WildernessLocation::addOptions(std::map<int,std::string>&){};

void WildernessLocation::handleInput(int, std::stack<GameState*>&, Player&, World&){};
