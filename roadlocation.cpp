#include "roadlocation.h"

RoadLocation::RoadLocation(int x, int y, int t) : WorldLocation(x,y) {
  type = t;
  switch(type){
    case NorthSouth:
      map_glyph = "\u2503"; // wtf
      //map_glyph = "|";
      break;
    case NorthWest:
      map_glyph = "\u251B";
      break;
    case NorthEast:
      map_glyph = "\u2517";
      break;
    case SouthEast:
      map_glyph = "\u250F";
      break;
    case SouthWest:
      map_glyph = "\u2513";
      break;
    case EastWest:
      map_glyph = "\u2501";
      break;
    case NorthSouthEast:
      map_glyph = "\u2523";
      break;
    case NorthSouthWest:
      map_glyph = "\u252B";
      break;
    case NorthEastWest:
      map_glyph = "\u253B";
      break;
    case SouthEastWest:
      map_glyph = "\u2533";
      break;
    case NorthSouthEastWest:
      map_glyph = "\u254B";
      break;
    default:
      break;
  };
}

int RoadLocation::getType(){
  return type;
}

WorldLocation* RoadLocation::connect(int side) {
  WorldLocation* newloc = nullptr;
  switch (side){
    case World::North:
      newloc = new RoadLocation(coords.first, coords.second+1, NorthSouth);
      break;
    case World::South:
      newloc = new RoadLocation(coords.first, coords.second-1, NorthSouth);
      break;
    case World::East:
      newloc = new RoadLocation(coords.first+1, coords.second, EastWest);
      break;
    case World::West:
      newloc = new RoadLocation(coords.first-1, coords.second, EastWest);
      break;
  };
  return newloc;
}
