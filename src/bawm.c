// BAWM

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/max.h"
#include "include/keyloader.h"

int main(void) {
  // Create a display object
  Display* disp;

  // Create window attributes
  XWindowAttributes attrib;

  // Create a Button event
  XButtonEvent butt; // Trying to make things shorter...

  // Create an event for X events
  XEvent event;

  // Try to open the display,
  // If I can't, then we want to exit
  // We'll use 0 instead of 0x00.
  // We're also adding support for :1
  // so that I can run bawm without
  // having to go into tty.

  if(!(disp = XOpenDisplay(0)) && !(disp = XOpenDisplay(":1"))){
    fprintf(stderr, "Can't open display on :0!\n");
    return 1;
  } else;

  // Set root window to Win + R (Super + R) [for root]
  XGrabKey(disp, XKeysymToKeycode(disp, XStringToKeysym("R")), Mod4Mask,
	  DefaultRootWindow(disp), True, GrabModeAsync, GrabModeAsync);



  // Grab Mouse (Left & Right) Inputs

  // Left
  XGrabButton(disp, 1, Mod4Mask, DefaultRootWindow(disp), True,
	      ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync,
	      GrabModeAsync, None, None);

  // Right
  XGrabButton(disp, 3, Mod4Mask, DefaultRootWindow(disp), True,
	      ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync,
	      GrabModeAsync, None, None);
      
  //:)
  butt.subwindow = None;

  // Event loop
  for (;;) {
    // Loop through X commands
    XNextEvent(disp, &event);

    switch (event.type){
      case 2:
        // Check if it's a subwindow
        if (event.xkey.subwindow != None){
          XRaiseWindow(disp, event.xkey.subwindow); // Raise window.
        }
        break;
      default:
        fprintf(stderr, "Can't handle event! Code: %d\n", event.type);
        return 127;
        break;
    }
  }

  // Close display
  XCloseDisplay(disp);

}
