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
}
