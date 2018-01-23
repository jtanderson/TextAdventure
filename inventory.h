#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <stdlib.h>
#include <ncurses.h>
#include <list>
#include "item.h"

class Inventory {
  protected:
    std::list<Item> itemList;
    unsigned int maxItems = 12; //could be dynamic but this is fine for now
    int gold = 5; //starting gold
  public:
    Inventory();
    ~Inventory();

    void addItem(Item&); //Loot 
    void useItem(Item&); //Consumable
    void buyItem(Item&); //From a vendor (super NYI)
    void sellItem(Item&);//Sell at any time for *value*
    void addGold(int); //Used to add gold to the player directly (loot, quests, etc)

    void display(); //Render inventory screen to gear_win 
};


#endif
