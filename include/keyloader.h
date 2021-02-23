#pragma once
#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h>
#include "keys.h"

#ifndef KEYBINDS
#define KEYBINDS


/* Loader. DO NOT MODIFY ANYTHING EXCEPT
ADDING METHODS TO RUN CERTAIN PROGRAMS,
LIKE BELOW. */
void loadKeyBinds(Display* disp){
    // This is loadKeyBinds(), which is a function
    // that has been recorvered because it's actually
    // not jank. It's difficult to use, but it should
    // work, short term..

    // I'll think of a long term solution. But for now,
    // we're keeping it here
    dmenurun(disp);
}

#endif // KEYBINDS