/* Get the dimensions of the display
and return them (X,Y) */
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef WIDTH
#define WIDTH

int getWidth(Display* disp){
    // Variables to initialize
    // before doing anything
    int scrNum = DefaultScreen(disp);
    int width = DisplayWidth(disp, scrNum);
    return width;
}

#endif //WIDTH

#ifndef HEIGHT
#define HEIGHT

int getHeight(Display* disp){
    // same as before
    return DisplayWidth(disp, DefaultScreen(disp));
}

#endif //HEIGHT