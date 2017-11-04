#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "xdrive.h"
#include "wiimote.h"
#include "calibrate.h"

void handle_mouse_event()
{
  int x, y;
  while (1)
  {
    get_click(&x, &y);
    if (!click_pos(1, x, y))
    {
      fprintf(stderr, "XTestFakeButtonEvent called failed\n");
      exit(EXIT_FAILURE);
    }
  }
}

int main(int argc, char *argv[])
{
  g_calibrated = 0;

  if (!init_display())
    exit(1);
  printf("display initialized\n");

  cwiid_wiimote_t *wiimote;
  char *address = NULL;
  if (argc > 1)
    address = argv[1];
  if (!(wiimote = init_wiimote(address)))
    exit(1);
  printf("wiimote initialized\n");

  printf("calibration: please select cursor\n");
  calibrate();

  handle_mouse_event();
  return 0;
}
