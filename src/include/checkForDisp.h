#pragma once

/* Basic Includes */
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>


#ifndef DEF_LOAD
#define DEF_LOAD

// defLoad is a function that attempts
// to connect to the :0 display,
// and if it can't it prints err to
// stderr
int defLoad(const char* err, Display* dpy){
  // Check if we can open display on :0
  // If not, print out that we can't 
  if (!(dpy = XOpenDisplay(0))){
    fprintf(stderr, "%s\n", err);
    return 1;
  }
}

#endif //DEF_LOAD

#ifndef OTH_LOAD
#define OTH_LOAD

// othLoad takes 3 parameters:
// 1) the error message tto be displayed
// 2) the display to connect to.
// 3) the display itself
int othLoad(const char* display, Display* dpy, const char* err){
  if(!(dpy = XOpenDisplay(display))){
    fprintf(stderr, "%s\n", err);
    return 1;
  }
}

#endif //OTH_LOAD
