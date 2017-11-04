#include <unistd.h>
#include <stdlib.h>

#include "wiimote.h"
#include "calibrate.h"
#include "xdrive.h"

cwiid_wiimote_t *wiimote;
int g_pipefd[2];
unsigned g_report_mode;

#define toggle_bit(bf,b)  \
(bf) = ((bf) & b)   \
  ? ((bf) & ~(b))  \
  : ((bf) | (b))

void cwiid_callback(cwiid_wiimote_t *wiimote, int mesg_count,
                    union cwiid_mesg mesg[], struct timespec *timestamp)
{
  int i, j;
  int valid_source;
  static int x = -1;
  static int y = -1;

  for (i=0; i < mesg_count; i++)
    {
      switch (mesg[i].type) {
      case CWIID_MESG_NUNCHUK:
      case CWIID_MESG_CLASSIC:
      case CWIID_MESG_ERROR:
      case CWIID_MESG_UNKNOWN:
        break;

      case CWIID_MESG_STATUS:
        printf("Status Report: battery=%d extension=",
               mesg[i].status_mesg.battery);
        printf("\n");
        break;
      case CWIID_MESG_BTN:
        printf("Button Report: %.4X\n", mesg[i].btn_mesg.buttons);
        break;
      case CWIID_MESG_ACC:
        printf("Acc Report: x=%d, y=%d, z=%d\n",
               mesg[i].acc_mesg.acc[CWIID_X],
               mesg[i].acc_mesg.acc[CWIID_Y],
               mesg[i].acc_mesg.acc[CWIID_Z]);
        break;
      case CWIID_MESG_IR:
        valid_source = 0;
        for (j = 0; j < CWIID_IR_SRC_COUNT; j++) {
          if (mesg[i].ir_mesg.src[j].valid) {
            valid_source = 1;
            printf("IR detected: (%d,%d) \n", mesg[i].ir_mesg.src[j].pos[CWIID_X],
                   mesg[i].ir_mesg.src[j].pos[CWIID_Y]);

            x = mesg[i].ir_mesg.src[j].pos[CWIID_X];
            y = mesg[i].ir_mesg.src[j].pos[CWIID_Y];
            write(g_pipefd[1], &x, sizeof (x));
            write(g_pipefd[1], &y, sizeof (y));
          }
        }
        if (!valid_source) {
          if (x != -1 || y != -1) // button was just push, terminate the click then
          {
            x = -1; y = -1;
            write(g_pipefd[1], &x, sizeof (x));
            write(g_pipefd[1], &y, sizeof (y));
          }

        }
        //printf("\n");
        break;
      }
    }
}

void set_led_state(cwiid_wiimote_t *wiimote, unsigned char led_state)
{
  if (cwiid_set_led(wiimote, led_state)) {
    fprintf(stderr, "Error setting LEDs \n");
  }
}

void set_rpt_mode(cwiid_wiimote_t *wiimote, unsigned char rpt_mode)
{
  if (cwiid_set_rpt_mode(wiimote, rpt_mode)) {
    fprintf(stderr, "Error setting report mode\n");
  }
}

cwiid_wiimote_t *init_wiimote(char *address)
{
  bdaddr_t bdaddr;        /* bluetooth device address */

  if (address) {
    str2ba(address, &bdaddr);
  }
  else {
    bdaddr = *BDADDR_ANY; // Connect to any wiimote
  }

  printf("Put Wiimote in discoverable mode now (press 1+2)...\n");
  if (!(wiimote = cwiid_open(&bdaddr, 0)))
  {
    fprintf(stderr, "Unable to connect to wiimote\n");
    return NULL;
  }
  g_report_mode = 0;
  toggle_bit(g_report_mode, CWIID_RPT_BTN);
  toggle_bit(g_report_mode, CWIID_RPT_IR);
  set_rpt_mode(wiimote, g_report_mode);

  if (pipe(g_pipefd) == -1)
  {
    fprintf(stderr, "Cannot create pipe\n");
    return NULL;
  }


  if (cwiid_set_mesg_callback(wiimote, cwiid_callback))
  {
    fprintf(stderr, "Unable to set message callback\n");
    return NULL;
  }
  cwiid_enable(wiimote, CWIID_FLAG_MESG_IFC);

  return wiimote;
}


void get_click(int *x, int *y)
{
  int tmpx = 0;
  int tmpy = 0;
  *x = -1;
  *y = -1;
  while (*x == -1 || *y == -1)
  {
    read(g_pipefd[0], &tmpx, sizeof (x));
    read(g_pipefd[0], &tmpy, sizeof (y));
    if (tmpx == -1 || tmpy == -1)
      break ;

    *x = tmpx;
    *y = tmpy;
  }

  printf("click (%i, %i)\n", *x, *y);
  warp(*x, *y, x, y);
}
