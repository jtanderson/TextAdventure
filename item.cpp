#include "item.h"

Item::Item() {
  //srand(time(0)); I think this is once-per-application not once-per-class
  generateItem();
}

Item::~Item() {};

// renamed for consistency and brevity
void Item::display() {
  wprintw(Display::gear_win, "%s -- %d\n", this->name.c_str(), this->value);
}

void Item::generateItem() {
  int randVal = rand() % 100;
  
  std::string junkArray[] = {"Rock", "Broken Tooth", "Ripped Pelt", "Unidentifiable Ooze", "Shiny Rock"};
  int junkValArray[] = {1, 5, 10, 3, 20};

  std::string equipArray[] = {"Knife", "Shortsword", "Greatsword", "Breastplate", "Gauntlets"};
  int equipValArray[] = {10, 25, 75, 40, 35};
  std::string preArray[] = {"Rusted", "Worn", "Gaudy", "Common", "Masterwork"};
  //  std::string suffArray[] = {" of More Health"};  NYI

  if (randVal < 15) { //You got equipment, generate it
    randVal = rand() % 5;    //Always get a base equipment
    int randPreVal = rand() % 5; //Always get a prefix
    
    name = preArray[randPreVal] + equipArray[randVal] + "";
    value = equipValArray[randVal];
  }
  else { //You got junk, sell it!
    randVal = rand() % 5;
    value = junkValArray[randVal];
    name = junkArray[randVal];
  }
  //  name = nameArray[randName];
}
