#include "display.h"

namespace Display {

  WINDOW *main_win, *text_win, *map_win, *gear_win,
         *gear_win_container, *map_win_container;

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
    keypad(text_win, TRUE);

    map_win_container = newwin(sub_h, sub_w, height-sub_h, 0);
    box(map_win_container, 0, 0);
    wrefresh(map_win_container);

    gear_win_container = newwin(sub_h, sub_w+(width%2), height-sub_h, sub_w);
    box(gear_win_container, 0, 0);
    wrefresh(gear_win_container);

    map_win = newwin(sub_h-2, sub_w-2, height-sub_h+1, 1);
    wrefresh(map_win);

    gear_win = newwin(sub_h-2, sub_w+(width%2)-2, height-sub_h+1, sub_w+1);
    wrefresh(gear_win);

  };
}
