#ifndef ROADLOCATION_H
#define ROADLOCATION_H

#include "world.h"
#include "worldlocation.h"
#include "wildernesslocation.h"
#include "util.h"

class RoadLocation : public WorldLocation {
  private:
    std::map<int,bool> connections; // {north, south, east, west}
    int type;
    static int connectionsToType(std::map<int,bool>);

  public:
    RoadLocation(int, int, int);
    RoadLocation(std::pair<int,int>, int);
    int getType();
    WorldLocation* connect(int) override;
    void addOptions(std::map<int,std::string>&) override;

    enum Type {
      NorthSouth = 1,
      NorthWest = 2,
      NorthEast = 3,
      SouthEast = 4,
      SouthWest = 5,
      EastWest = 6,
      NorthSouthEast = 7,
      NorthSouthWest = 8,
      NorthEastWest = 9,
      SouthEastWest = 10,
      NorthSouthEastWest = 11
    };
};

#endif
