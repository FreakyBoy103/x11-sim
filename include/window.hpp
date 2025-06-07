#ifndef WINDOW_H
#define WINDOW_H

#include <X11/keysym.h>
#include <X11/Xutil.h>
#include <Imlib2.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>

typedef struct {
  Display *display;
  Window window;
  int screen;
} AppContext;

AppContext initWindow();

#endif
