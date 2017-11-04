#include <stdlib.h>
#include "xdrive.h"

Display *g_display = NULL;

Display *init_display()
{
  g_display = XOpenDisplay((char *) getenv("DISPLAY"));
  return g_display;
}

int mousemove(int x, int y)
{
  XTestFakeMotionEvent(g_display, 0, x, y, CurrentTime);
  return XFlush(g_display);
}

int click(int button)
{
  XTestFakeButtonEvent(g_display, button, True, CurrentTime);
  return XFlush(g_display);
}

int click_pos(int button, int x, int y)
{
  mousemove(x, y);
  return click(button);
}
