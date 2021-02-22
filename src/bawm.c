// BAWM

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Create a display object
  Display* disp;

  // Create window attributes
  XWindowAttrbutes attrib;

  // Create a Button event
  XButtonEvent butt; // Trying to make things shorter...

  // Create an event for X events
  XEvent event;

  // Try to open the display,
  // If I can't, then we want to exit
  // We'll use 0 instead of 0x00.

  if(!(disp = XOpenDisplay(0))){
    fprintf(stderr, "Can't open display!");
    return 1;
  }
}
