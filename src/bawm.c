/*
   BAWM
 */
#include <xcb/xcb.h>

int main() {
  // Connect to the X server
  xcb_connection_t *connection = xcb_connect (NULL, NULL); // Usually, it's :0
}
