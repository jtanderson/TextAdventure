#include "inventory.h"

Inventory::Inventory(){
  //Instantiate itemList? happens automatically
  //because it is not a reference
  
}

Inventory::~Inventory(){};

// Renamed to display because "Inventory" is implied
void Inventory::display() {
  wclear(Display::gear_win);
  wprintw(Display::gear_win, "Bag:\n");
  
  // replacing for brevity
  //for (std::list<Item>::iterator it = itemList.begin(); itr != itemList.end();)
  for (auto it = itemList.begin(); it != itemList.end();++it)
  {
    //Figure out how to display each item
    it->display(); // equiv to (*it).display();
  }
  //wprintw(Display::gear_win, "tempDisplay");
  wrefresh(Display::gear_win);
}

void Inventory::addItem(Item& item) {
  itemList.push_back(item);
}

void Inventory::useItem(Item& item) {

  for (auto it = itemList.begin(); it != itemList.end();++it)
  {
    Item tempItem = *it;
    if (item.name == tempItem.name)
    {
      itemList.erase(it);
    }
  }
  
}

void Inventory::buyItem(Item& item) {} //NYI

void Inventory::sellItem(Item& item) { //This can be used anywhere atm
  //Somehow add gold to the player
  //itemList.erase(item);
}
