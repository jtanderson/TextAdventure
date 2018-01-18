#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
//#include <fstream>
#include <stdarg.h>
#include <stdio.h>

namespace Logger {
  enum Level {
    DEBUG = 1,
    INFO  = 2,
    ERROR = 3
  };

  extern int log_level;
  //std::ofstream log_file;
  extern FILE* log_file;

  extern void init(int);
  extern void close();

  extern void debug(const char* fmt, ...);
  extern void info(const char* fmt, ...);
  extern void err(const char* fmt, ...);

  void write(int, const char* fmt, va_list);
  bool is_init();
};

#endif
