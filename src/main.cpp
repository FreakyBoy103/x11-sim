#include <X11/Xlib.h>
#include <vector>
#include <iostream>
#include <limits>

#include "../include/window.hpp"
#include "../include/sphere.h"

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 600
#define SPHERE_SIZE 100

//Globals
float gravity = 0.5;
#include <limits>
struct PressedKeys{
  bool r;
};

//Functions
void key_manager(Display *display, PressedKeys *pressedKeys);
float input_value(const char* prompt, float min, float max);

int main(){

  gravity = input_value("Insert gravity", 0.0, 20.0);


  float sphere_el = input_value("Insert el", 0.0, 20.0);
  

  AppContext context = initWindow();
  Display *display = context.display;
  Window window = context.window;
  int screen = context.screen;
  Pixmap pix_buffer = XCreatePixmap(display, window, WINDOW_WIDTH, WINDOW_HEIGHT, DefaultDepth(display, screen));

  //Init all the sphere
  std::vector<Sphere> sphere_list;
  sphere_list.push_back(Sphere(WINDOW_WIDTH / 2, 70, sphere_el, SPHERE_SIZE));

  while(1){

    //Clear screen from old frame/set background
    XSetForeground(display, DefaultGC(display, screen), WhitePixel(display, screen));
    XFillRectangle(display, pix_buffer, DefaultGC(display, screen), 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    //Keys manager
    PressedKeys pressedKeys;
    key_manager(display, &pressedKeys);

    //Draw sphere
    int floor = WINDOW_HEIGHT - SPHERE_SIZE;
    XSetForeground(display, DefaultGC(display, screen), BlackPixel(display, screen));
    for(Sphere& sphere : sphere_list){
      XFillArc(display, pix_buffer, DefaultGC(display, screen), sphere.x, sphere.y, SPHERE_SIZE, SPHERE_SIZE, 0*64, 360*64);

      sphere.sphere_loop(gravity, WINDOW_HEIGHT);

    }

    //Show new draw
    XCopyArea(display, pix_buffer, window, DefaultGC(display, screen), 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
    XFlush(display);

    usleep(16000);

  }
}



int is_real_keyrelease(Display *display, XEvent *event) {

  XEvent next;
  if (XPending(display)) {
    XPeekEvent(display, &next);
    if (next.type == KeyPress &&
        next.xkey.time == event->xkey.time &&
        next.xkey.keycode == event->xkey.keycode) {
      XNextEvent(display, &next); 
      return 0;
    }
  }
  return 1;
}

void key_manager(Display *display, PressedKeys *pressedKeys){
  XEvent ev;
  XNextEvent(display, &ev);
  
  if (ev.type == KeyPress) {
    KeySym key = XLookupKeysym(&ev.xkey, 0);
    if (key == XK_k) pressedKeys->r = true;
  }

  if (ev.type == KeyRelease) {
    if (is_real_keyrelease(display, &ev)) {
      KeySym key = XLookupKeysym(&ev.xkey, 0);
      if (key == XK_k) pressedKeys->r = false;
    }
  }
}


float input_value(const char* prompt, float min, float max) {
    float value;
    while(true) {
        std::cout << prompt << " [" << min << "-" << max << "]: ";
        std::cin >> value;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input non valido. Inserisci un numero.\n";
            continue;
        }

        if(std::cin.peek() != '\n') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input contiene caratteri non numerici. Riprova.\n";
            continue;
        }

        if(value < min || value > max) {
            std::cout << "Il valore deve essere tra " << min << " e " << max << ".\n";
            continue;
        }

        break;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}


