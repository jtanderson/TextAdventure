#include "item.h"

Item::Item() {
  value = 5;
  name = "testItem1";
}

Item::~Item() {};

// renamed for consistency and brevity
void Item::display() {
  wprintw(Display::text_win, "%s\n", this->name);
}
