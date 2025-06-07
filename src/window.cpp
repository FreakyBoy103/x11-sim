#include "../include/window.hpp"

#include <iostream>

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 600

AppContext initWindow(){
  AppContext ctx;
  ctx.display = XOpenDisplay(NULL);

  if(!ctx.display){
    std::cout << "Can't open display \n" ;
    exit(1);
  }

  ctx.screen = DefaultScreen(ctx.display);
  ctx.window = XCreateSimpleWindow(
    ctx.display,
    RootWindow(ctx.display, ctx.screen),
    0, 0,
    WINDOW_WIDTH, WINDOW_HEIGHT,
    1,
    BlackPixel(ctx.display, ctx.screen),
    WhitePixel(ctx.display, ctx.screen)
  );

  XSelectInput(ctx.display, ctx.window, KeyPressMask | KeyReleaseMask | ExposureMask);
  XMapWindow(ctx.display, ctx.window);
  XStoreName(ctx.display, ctx.window, "Simulator");

  //Set window fixed size
  XSizeHints *hints = XAllocSizeHints();
  hints->flags = PMinSize | PMaxSize;
  hints->min_width = hints->max_width = WINDOW_WIDTH;
  hints->min_height = hints->max_height = WINDOW_HEIGHT;
  XSetWMNormalHints(ctx.display, ctx.window, hints);
  XFree(hints);

  std::cout << "Display online: " << ctx.window << "\n";

  return ctx;
}



