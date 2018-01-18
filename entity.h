#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <functional>

#include "display.h"
#include "inventory.h"
#include "logger.h"
#include "util.h"

class Entity {
  private:
    std::string id;
  public:
    Entity();
    virtual ~Entity();
};

#endif
