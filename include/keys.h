#pragma once
#include <X11/Xos.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

// If you're using a launcher like DMENU, use the example above,
// else, follow this
Window alacrun(Display* disp){
    Window win;
    
    // Create the window, and make sure that it DOES exist
    // We're going to use Super + T for this, as wellas alacritty
    // for the terminal emulator
    

    // Keybind
    if (XGrabKey(disp, XKeysymToKeycode(disp, XStringToKeysym("T")), Mod4Mask,
        DefaultRootWindow(disp), True, GrabModeAsync, GrabModeAsync)){
            // Spawn the window
            system("alacritty"); // I'm gonna want to refactor this.
    }

    // Now we're going to check if the window exists

    // Move the window to the center of the screen.

    return win;
}

#endif // KEYS