#include "util.h"

namespace Util {
  // Taken from
  // https://stackoverflow.com/questions/21842849/how-to-generate-a-random-string-in-c
  std::string gen_rand_str(int len){
    const char* charmap = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int charmapLength = std::strlen(charmap);
    auto generator = [&](){ return charmap[rand()%charmapLength]; };
    std::string result;
    result.reserve(len);
    generate_n(back_inserter(result), len, generator);
    return result;
  }

  std::pair<int,int> getSide(std::pair<int,int> c,int d){
    std::pair<int,int> new_loc = c;
    switch(d){
      case World::North:
        new_loc.second++;
        break;
      case World::South:
        new_loc.second--;
        break;
      case World::East:
        new_loc.first++;
        break;
      case World::West:
        new_loc.first++;
        break;
    };
    return new_loc;
  }
}
