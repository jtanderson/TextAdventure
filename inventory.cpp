#include "inventory.h"

Inventory::Inventory(){
  //Instantiate itemList?
  std::list<Item> itemList;
}

Inventory::~Inventory();

void Inventory::displayInventory() {
  wprintw(Display::gear_win, "tempDisplay");
  
  for (std::list<Item>::iterator it = itemList.begin(); itr != itemList.end();)
  {
    //Figure out how to display each item
    ++it;
  }
}

void Inventory::addItem(Item& item) {
  itemList.push_back(item);
}

void Inventory::useItem(Item& item) {
  itemList.erase(item);
}

void Inventory::buyItem(Item& item) {} //NYI

void Inventory::sellItem(Item& item) { //This can be used anywhere atm
  //Somehow add gold to the player
  itemList.erase(item);
}
