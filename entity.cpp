#include "entity.h"

Entity::Entity(){
  id = Util::gen_rand_str(16);
  Logger::debug("Entity id: %s\n", id.c_str());
};

Entity::~Entity(){
};
