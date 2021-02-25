/* Get the dimensions of the display
and return then (X,Y) */
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