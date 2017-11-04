#ifndef __XDRIVE_H__
#define __XDRIVE_H__

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>

extern Display *g_display;

Display *init_display();
int mousemove(int x, int y);
int click(int button);
int click_pos(int button, int x, int y);

#endif //  __XDRIVE_H__
