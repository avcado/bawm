#include <X11/Xos.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

Window Window_With_Name(Display *disp, Window win, char *name){
    Window *children, dummy;
    unsigned int nchildren;
    int i;
    Window w=0;
    char *window_name;

    if (XFetchName(disp, win, &window_name) && (strstr(window_name, name) == window_name)) return(win);

    if (!XQueryTree(disp, win, &dummy, &dummy, &children, &nchildren)) return(0);

    for (i=0; i<nchildren; i++){
        w = Window_With_Name(disp, children[i], name);
        if (w) break;
    }
    if (children) XFree ((char *)children);
        return(w);
}