#ifndef UTIL_H
#define UTIL_H

#include <random>
#include <algorithm>
#include <string>
#include <cstring>

#include "world.h"

namespace Util {
  extern std::string gen_rand_str(int);
  extern std::pair<int,int> getSide(std::pair<int,int>,int);
};

#endif
