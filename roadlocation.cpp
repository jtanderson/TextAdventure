#include "roadlocation.h"

RoadLocation::RoadLocation(std::pair<int,int> c, int t) : RoadLocation(c.first, c.second, t) { };

RoadLocation::RoadLocation(int x, int y, int t) : WorldLocation(x,y) {
  type = t;

  connections[World::North] = false;
  connections[World::South] = false;
  connections[World::East] = false;
  connections[World::West] = false;

  switch(type){
    case NorthSouth:
      map_glyph = "\u2503";
      connections[World::North] = true;
      connections[World::South] = true;
      break;
    case NorthWest:
      map_glyph = "\u251B";
      connections[World::North] = true;
      connections[World::West] = true;
      break;
    case NorthEast:
      map_glyph = "\u2517";
      connections[World::North] = true;
      connections[World::East] = true;
      break;
    case SouthEast:
      map_glyph = "\u250F";
      connections[World::South] = true;
      connections[World::East] = true;
      break;
    case SouthWest:
      map_glyph = "\u2513";
      connections[World::South] = true;
      connections[World::West] = true;
      break;
    case EastWest:
      map_glyph = "\u2501";
      connections[World::East] = true;
      connections[World::West] = true;
      break;
    case NorthSouthEast:
      map_glyph = "\u2523";
      connections[World::North] = true;
      connections[World::South] = true;
      connections[World::East] = true;
      break;
    case NorthSouthWest:
      map_glyph = "\u252B";
      connections[World::North] = true;
      connections[World::South] = true;
      connections[World::West] = true;
      break;
    case NorthEastWest:
      map_glyph = "\u253B";
      connections[World::North] = true;
      connections[World::East] = true;
      connections[World::West] = true;
      break;
    case SouthEastWest:
      map_glyph = "\u2533";
      connections[World::South] = true;
      connections[World::East] = true;
      connections[World::West] = true;
      break;
    case NorthSouthEastWest:
      map_glyph = "\u254B";
      connections[World::North] = true;
      connections[World::South] = true;
      connections[World::East] = true;
      connections[World::West] = true;
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
  bool needStraight = true;

  if (connections[side]){
    std::map<int,bool> newConnections = {
      {World::North, false},
      {World::South, false},
      {World::East, false},
      {World::West, false}
    };

    newConnections[-1*side] = true;
    // 70% to keep going straight
    if (rand()%100 + 1 <= 70){
      newConnections[side] = true;
      needStraight = false;
    }
    // 20% to turn to either side
    if (rand()%100 + 1 <= 20){
      newConnections[(side%2 + 1)] = true;
      needStraight = false;
    }
    if (rand()%100 + 1 <= 20){
      newConnections[-1*(side%2 + 1)] = true;
      needStraight = false;
    }

    // If all failed, make it straight
    // TODO: just make a dead-end type?
    if (needStraight){
      Logger::debug("Need to extend road\n");
      newConnections[side] = true;
    }

    newloc = new RoadLocation(Util::getSide(coords,side), connectionsToType(newConnections));
  } else {
    newloc = new WildernessLocation(Util::getSide(coords,side));
  }

  return newloc;
}

int RoadLocation::connectionsToType(std::map<int,bool> conns){
  std::map<std::string,int> str_to_type = {
    {"NorthSouth", NorthSouth},
    {"NorthWest",  NorthWest},
    {"NorthEast",  NorthEast},
    {"SouthEast",  SouthEast},
    {"SouthWest",  SouthWest},
    {"EastWest",   EastWest},
    {"NorthSouthEast", NorthSouthEast},
    {"NorthSouthWest", NorthSouthWest},
    {"NorthEastWest", NorthEastWest},
    {"SouthEastWest", SouthEastWest},
    {"NorthSouthEastWest", NorthSouthEastWest},
  };

  std::string str = "";
  if (conns[World::North]){
    str += "North";
  }
  if (conns[World::South]){
    str += "South";
  }
  if (conns[World::East]){
    str += "East";
  }
  if (conns[World::West]){
    str += "West";
  }

  auto search = str_to_type.find(str);
  if (search != str_to_type.end()){
    return search->second;
  } else {
    Logger::err("Road type not found: %s\n", str.c_str());
    return 0;
  }
}

void RoadLocation::addOptions(std::map<int,std::string>& opts) {
  // Have to assume for now that options always start at 1
  for (auto it=connections.begin(); it!=connections.end(); ++it){
    if (it->second){
      opts[opts.size()+1] = "Walk " + World::getDirName(it->first);
      choices[opts.size()] = it->first;
    }
  }
}

void RoadLocation::handleInput(int choice,std::stack<GameState*>& stack,Player& p,World& w) {
  auto search = choices.find(choice);
  if (search==choices.end()){
    wprintw(Display::text_win, "Invalid choice.\n");
    Logger::err("Invalid choice: %d\n", choice);
    return;
  }

  p.move(search->second);
  delete stack.top();
  stack.pop();
  stack.push(new TravelState(w.getLocationAt(p.getPos()), search->second));
}
