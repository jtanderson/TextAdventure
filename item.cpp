#include "item.h"

Item::Item() {
  value = 5;
  name = "testItem1";
}

Item::~Item() {};

// renamed for consistency and brevity
void Item::display() {
  wprintw(Display::gear_win, "%s\n", this->name.c_str());
}
