#ifndef ROADLOCATION_H
#define ROADLOCATION_H

#include "world.h"
#include "worldlocation.h"

class RoadLocation : public WorldLocation {
  private:
    //bool dirs[4]; // {north, south, east, west}
    int type;

  public:
    RoadLocation(int, int, int);
    int getType();
    WorldLocation* connect(int) override;

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
