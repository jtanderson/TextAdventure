#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <stdlib.h>
#include "display.h" // Display

class Item {
  protected:
  public:
    int value;
    std::string name;
    Item();
    virtual ~Item();
    void display();
};

#endif
