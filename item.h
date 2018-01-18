#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <stdlib.h>
#include "display.h" // Display

class Item {
  protected:
    int value;
    std::string name;
  public:
    Item();
    virtual ~Item();
    void display();
};

#endif
