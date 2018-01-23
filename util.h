#ifndef UTIL_H
#define UTIL_H

#include <random>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

//#include "world.h"

namespace Util {
  enum Direction {
    North = 1,
    South = -1,
    East  = 2,
    West  = -2
  };

  extern std::string gen_rand_str(int);

  // Takes a coodinate pair and a World::Direction
  extern std::pair<int,int> getSide(std::pair<int,int>,int);
  extern std::string getDirName(int);
};

#endif
