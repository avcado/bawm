#pragma once
#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h

#ifndef KEYS
#define KEYS

// Load dmenu
void dmenurun(Display* disp){
    if (XGrabKey(disp, XKeysymToKeycode(disp, XStringToKeysym("D")), Mod4Mask,
        DefaultRootWindow(disp), True, GrabModeAsync, GrabModeAsync)){
            // Run dmenu with system();
            // Probably bad practice..
            system("dmenu_run");
    }
}

#endif // KEYS