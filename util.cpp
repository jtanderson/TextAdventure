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
      case Util::North:
        new_loc.second++;
        break;
      case Util::South:
        new_loc.second--;
        break;
      case Util::East:
        new_loc.first++;
        break;
      case Util::West:
        new_loc.first--;
        break;
    };
    return new_loc;
  }

  std::string getDirName(int d){
    switch(d){
      case North:
        return "North";
      case South:
        return "South";
      case East:
        return "East";
      case West:
        return "West";
      default:
        return "";
    };
    /*
    std::map<int, std::string> DirNames = {
      {Util::North, "North"},
      {Util::South, "South"},
      {Util::East,  "East"},
      {Util::West,  "West"}
    };

    auto search = DirNames.find(d);
    if (search != DirNames.end()){
      return search->second;
    } else {
      return "";
    }
    */
  };
}
