#ifndef __WIIMOTE_H__
#define __WIIMOTE_H__

#include <cwiid.h>

extern int g_pipefd[2];

cwiid_mesg_callback_t cwiid_callback;                                                       
cwiid_wiimote_t *init_wiimote(char *address);
void get_click(int *x, int *y);

#endif //  __WIIMOTE_H__
