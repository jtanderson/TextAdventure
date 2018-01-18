#include "logger.h"

namespace Logger {

  int log_level;
  FILE* log_file;

  void init(int level){
    log_level = level;
    log_file = fopen("log.txt", "a+");
  }

  void close(){
    fprintf(log_file, "===========================================\n");
    fclose(log_file);
  }

  void debug(const char* fmt, ...){
    va_list argptr;
    va_start(argptr, fmt);

    write(DEBUG, fmt, argptr);

    va_end(argptr);
  }

  void info(const char* fmt, ...){
    va_list argptr;
    va_start(argptr, fmt);

    write(INFO, fmt, argptr);

    va_end(argptr);
  }

  void err(const char* fmt, ...){
    va_list argptr;
    va_start(argptr, fmt);

    write(ERROR, fmt, argptr);

    va_end(argptr);
  }

  void write(int level, const char* fmt, va_list args){
    if ( log_level <= level ){
      vfprintf(log_file, fmt, args);
      fflush(log_file);
    }
  }

  bool is_init(){
    return log_level > -1;
  }
};
