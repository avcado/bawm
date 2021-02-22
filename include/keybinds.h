

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

// An example: running alacritty with Super + T
void alacrittyrun(Display* disp) {
    if (XGrabKey(disp, XKeysymToKeycode(disp, XStringToKeysym("T")),
        mod, DefaultRootWindow(disp), True, GrabModeAsync,
        GrabModeAsync)){
            // Now we're gonna run alacritty
            // This is probably bad practice,
            // But it works
            system("alacritty");
        }
}

// Another example if you'd like it
// running dmenu with Mod + D
void dmenurun(Display* disp){
    if (XGrabKey(disp, XKeysymToKeycode(disp, XStringToKeysym("D")),
        mod, DefaultRootWindow(disp), True, GrabModeAsync,
        GrabModeAsync)){
            // Run it
            system("dmenu_run");
        }
}

// Add your keybinds here.
// Check the examples before adding keybinds
// (above these comments)

#endif // KEYBINDS

#ifndef LOAD_KEYBINDS
#define LOAD_KEYBINDS

void loadKeyBinds(Display* disp){
    // This is an example of running multiple
    // Key handlers.
    
    alacrittyrun(disp);
    dmenurun(disp);
}

#endif // LOAD_KEYBINDS
