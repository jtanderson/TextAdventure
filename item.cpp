#include "item.h"
#include "entity.h" //Player

Item::Item() {
  value = 5;
  name = "testItem1";

}

Item::~Item() {};

void Item::printItem() {
  wprintw(Display::text_win, this->name);
}
