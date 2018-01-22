#include "item.h"

Item::Item() {
  //srand(time(0)); I think this is once-per-application not once-per-class
  
  int randVal = rand() % 100;
  value = randVal;

  int randName = rand() % 5;
  std::string nameArray[] = {"Rock", "Broken Tooth", "Rusted Blade", "Shortsword", "Gleaming Greatsword of the Marauder"};
  name = nameArray[randName];
}

Item::~Item() {};

// renamed for consistency and brevity
void Item::display() {
  wprintw(Display::gear_win, "%s -- %d\n", this->name.c_str(), this->value);
}
