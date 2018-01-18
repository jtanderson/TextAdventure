#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "display.h"
#include "inventory.h"

class Entity {
  public:
    Entity(){};
    virtual ~Entity(){};
};

#endif
