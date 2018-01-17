#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <stdlib.h>
#include <ncurses.h>
#include <item.h>

class Inventory {
  public:
    Inventory(){};
    virtual ~Inventory(){};

    Inventory::addItem(Item&);
};


#endif
