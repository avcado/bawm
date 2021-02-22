// BAWM

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

#include "max.h"
#include "keybinds.h"

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

  if(!(disp = XOpenDisplay(0))){
    fprintf(stderr, "Can't open display!\n");
    return 1;
  }

  // This is how we're going to be able to load in for
  // Xephyr.

  // NOTE: This is extremely hacky, and I don't suggest using
  // it for releases later on.
  if (!(disp = XOpenDisplay(":1"))){
    fprintf(stderr, "Can't open display!\n");
    return 1;
  }

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

  butt.subwindow = None;

  // Event loop
  for (;;) {
    // Loop through X commands
    XNextEvent(disp, &event);
    switch (event.type){
	
      // Check for keystrokes
      case KeyPress:
        // Coming from keybinds.h, remember: call the loadKeyBinds() function
        loadKeyBinds(disp);
	      break;
      default:
        printf("No keybind gotten\n");
        break;
    }
  }

  // Close display
  XCloseDisplay(disp);

}
