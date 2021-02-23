

#pragma once
#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef MODMASK
#define MODMASK

// Mod4Mask / Super
unsigned int mod = Mod4Mask; // Change this to your
// hearts desire.

#endif // MODMASK

#ifndef KEYBINDS
#define KEYBINDS

void loadKeyBinds(Display* disp){
    // This is an example of running multiple
    // key handlers.
    if (XGrabKey(disp, XKeysymToKeycode(disp, XStringToKeysym("D")), mod,
        DefaultRootWindow(disp), True, GrabModeAsync,
        GrabModeAsync)){
            // Run dmenu with system();
            // Probably bad practice..
            system("dmenu");
    }
}

#endif // KEYBINDS