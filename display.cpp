#include "display.h"

namespace Display {

  WINDOW *main_win, *text_win, *map_win, *gear_win;

  void init(){
    int width, height;
    int sub_w, sub_h;

    initscr();
    cbreak();
    noecho();

    refresh();
    height = LINES;
    width = COLS;

    sub_w = width/2;
    sub_h = 15;

    main_win = newwin(height-sub_h, width, 0, 0);
    box(main_win, 0, 0);
    wrefresh(main_win);

    text_win = newwin(height-sub_h-2, width-2, 1, 1);
    scrollok(text_win, TRUE);
    wrefresh(text_win);

    map_win = newwin(sub_h, sub_w, height-sub_h, 0);
    box(map_win, 0, 0);
    wrefresh(map_win);

    gear_win = newwin(sub_h, sub_w+(width%2), height-sub_h, sub_w);
    box(gear_win, 0, 0);
    wrefresh(gear_win);
  };
}
