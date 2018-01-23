#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <stdlib.h>
#include "display.h" // Display

class Item {
  protected:
    void generateItem();
  public:
    int value;
    std::string name;
    int boostAtk;   //Boost attack roll
    int boostDmg;   //Boost attack dmg
    int boostHp;    //Boost health maximum
    int boostArmor; //Boost AC

    Item();
    virtual ~Item();
    void display();
};

#endif
