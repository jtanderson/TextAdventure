#ifndef DISPLAY
#define DISPALY

#include <ncurses.h>
#include <string>

namespace Display {

  extern WINDOW *main_win, *text_win, *map_win, *gear_win;

  extern void init();
};

#endif
