#include "inventory.h"

Inventory::Inventory(){
  //Instantiate itemList? happens automatically
  //because it is not a reference
  
}

Inventory::~Inventory(){};

// Renamed to display because "Inventory" is implied
void Inventory::display() {
  wclear(Display::gear_win);

  // get the screen size 
  //int maxItems, mapw; // height of the window is the max number of items we can display, seems to always be 13?
  //getmaxyx(Display::gear_win, maxItems, mapw);

  //Display bag header
  wprintw(Display::gear_win, "BAG [");
  //Display capacity in top line, ' ' is free slot, '=' is filled slot
  for (unsigned int it = 0; it != maxItems-1; it++) {
    if (it < itemList.size()) {
      wprintw(Display::gear_win, "=");
    }
    else {
      wprintw(Display::gear_win, " ");
    }
  }
  wprintw(Display::gear_win, "] %d / %d -- %dgp\n", itemList.size(), maxItems, gold);

  //Display bag contents
  for (auto it = itemList.begin(); it != itemList.end();++it)
  {
    wprintw(Display::gear_win, " -> ");
    it->display(); // equiv to (*it).display();
  }
  wrefresh(Display::gear_win);
}

void Inventory::addItem(Item& item) {
  if (itemList.size() < maxItems) {
    itemList.push_back(item);
  }
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

void Inventory::sellItem(Item& item) { 
  //This can be used anywhere atm
  //Somehow add gold to the player
  for (auto it = itemList.begin(); it != itemList.end();++it)
  {
    Item tempItem = *it;
    if (item.name == tempItem.name)
    {
      gold += item.value;
      itemList.erase(it);
    }
  }
}

void Inventory::addGold(int newGold) {
  gold += newGold;
}
