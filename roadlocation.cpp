#include "roadlocation.h"

RoadLocation::RoadLocation(std::pair<int,int> c, int t) : RoadLocation(c.first, c.second, t) { };

RoadLocation::RoadLocation(int x, int y, int t) : WorldLocation(x,y) {
  type = t;

  connections[Util::North] = false;
  connections[Util::South] = false;
  connections[Util::East] = false;
  connections[Util::West] = false;

  switch(type){
    case NorthSouth:
      map_glyph = "\u2503";
      connections[Util::North] = true;
      connections[Util::South] = true;
      break;
    case NorthWest:
      map_glyph = "\u251B";
      connections[Util::North] = true;
      connections[Util::West] = true;
      break;
    case NorthEast:
      map_glyph = "\u2517";
      connections[Util::North] = true;
      connections[Util::East] = true;
      break;
    case SouthEast:
      map_glyph = "\u250F";
      connections[Util::South] = true;
      connections[Util::East] = true;
      break;
    case SouthWest:
      map_glyph = "\u2513";
      connections[Util::South] = true;
      connections[Util::West] = true;
      break;
    case EastWest:
      map_glyph = "\u2501";
      connections[Util::East] = true;
      connections[Util::West] = true;
      break;
    case NorthSouthEast:
      map_glyph = "\u2523";
      connections[Util::North] = true;
      connections[Util::South] = true;
      connections[Util::East] = true;
      break;
    case NorthSouthWest:
      map_glyph = "\u252B";
      connections[Util::North] = true;
      connections[Util::South] = true;
      connections[Util::West] = true;
      break;
    case NorthEastWest:
      map_glyph = "\u253B";
      connections[Util::North] = true;
      connections[Util::East] = true;
      connections[Util::West] = true;
      break;
    case SouthEastWest:
      map_glyph = "\u2533";
      connections[Util::South] = true;
      connections[Util::East] = true;
      connections[Util::West] = true;
      break;
    case NorthSouthEastWest:
      map_glyph = "\u254B";
      connections[Util::North] = true;
      connections[Util::South] = true;
      connections[Util::East] = true;
      connections[Util::West] = true;
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
  int orth_dir;

  if (connections[side]){
    Logger::debug("Connecting to %s side.\n", Util::getDirName(side).c_str());
    std::map<int,bool> newConnections = {
      {Util::North, false},
      {Util::South, false},
      {Util::East, false},
      {Util::West, false}
    };

    Logger::debug("Set side index %d to true.\n", -1*side);
    Logger::debug("New road connects %s.\n", Util::getDirName(-1*side).c_str());
    newConnections[-1*side] = true;

    orth_dir = (std::abs(side)%2)+1;

    // 70% to keep going straight
    if (rand()%100 + 1 <= 70){
      newConnections[side] = true;
      Logger::debug("Adding %s path.\n", Util::getDirName(side).c_str());
      needStraight = false;
    }
    // 20% to turn to either side
    if (rand()%100 + 1 <= 20){
      Logger::debug("Adding %s path.\n", Util::getDirName(orth_dir).c_str());
      newConnections[orth_dir] = true;
      needStraight = false;
    }
    if (rand()%100 + 1 <= 20){
      Logger::debug("Adding %s path.\n", Util::getDirName(-1*orth_dir).c_str());
      newConnections[-1*orth_dir] = true;
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
  if (conns[Util::North]){
    str += "North";
  }
  if (conns[Util::South]){
    str += "South";
  }
  if (conns[Util::East]){
    str += "East";
  }
  if (conns[Util::West]){
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
      opts['0'+opts.size()+1] = "Walk " + Util::getDirName(it->first);
      choices[opts.size()] = it->first;
    }
  }
}

void RoadLocation::handleInput(int choice,std::stack<GameState*>& stack,Player& p,World& w) {
  int dir = 0;

  Logger::info("RoadLocation handling choice: %d\n", choice);

  switch(choice){
    case KEY_UP:
      Logger::debug("Pressed up arrow\n");
      if (connections[Util::North]){
        dir = Util::North;
      }
      break;
    case KEY_DOWN:
      if (connections[Util::South]){
        dir = Util::South;
      }
      break;
    case KEY_LEFT:
      if (connections[Util::West]){
        dir = Util::West;
      }
      break;
    case KEY_RIGHT:
      if (connections[Util::East]){
        dir = Util::East;
      }
    default:
      auto search = choices.find(choice-'0');
      if (search!=choices.end()){
        dir = search->second;
      }
      break;
  }

  //wprintw(Display::text_win, "You walk %s.\n", Util::getDirName(search->second).c_str());

  if (dir != 0){
    p.move(dir);
    delete stack.top();
    stack.pop();
    stack.push(new TravelState(w.getLocationAt(p.getPos()), dir));
  } else {
      wprintw(Display::text_win, "Invalid choice.\n");
      Logger::err("Invalid choice: %d\n", choice);
  }
}
