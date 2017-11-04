#!/usr/bin/env python
# -*- coding: utf-8 -*-

import cwiid

## Configuration
#wiimote_hwaddr = '' # Use your address to speed up the connection proccess
wiimote_hwaddr = '00:22:D7:95:53:4F'

def connect(wm_addr = ''):
    '''Connects and syncs with a wiimote
    wm_addr - Is a string representing the hwaddr of the wiimote we will try to
            connect, or none to try to connect with any discoverable device
            for example "00:19:1D:5D:5D:DC"'''

    pygame.display.flip() # called now because cwiid.Wiimote is a blocking call

    # This could be done in a thread to allow pygame to draw while searching
    # but this is only a test
    try:
        return cwiid.Wiimote(wm_addr)
    except:
        print "Error conectando con wiimote " + str(wm_addr)


def wmplugin_init(id, wiimote_arg):
    #global wiimote

    #wiimote = wiimote_arg
    wmplugin.set_rpt_mode(id, cwiid.RPT_IR | cwiid.RPT_BTN)
    return

def wmplugin_info():
    return [], \
      [("X", wmplugin.REL | wmplugin.ABS, 1024, 0, 0, 0), \
       ("Y", wmplugin.REL | wmplugin.ABS, 768, 0, 0, 0)], \
    []

def wmplugin_exec(messages, buton=[0]):
    '''Wiimote callback managing method
    Recieves a message list, each element is different, see the libcwiid docs'''
    x = y = 0

    for msg in messages:

        if msg[0] == cwiid.MESG_BTN:
            # msg is of the form (cwiid.MESG_BTN, cwiid.BTN_*)
            buton[0] = msg[1]

        if msg[0] == cwiid.MESG_IR:
            if screen:
                # red dot for the sources
                [screen.fill((255, 0, 0), (point, (4, 4))) \
                        for point in ir_sensor.get_positions_points(msg)]  

            if buton[0] & cwiid.BTN_B == 0 :
                x, y = (0, 0) 

    return [], (x, y)

if __name__ == '__main__':
    import pygame
    from pygame.locals import *
    runing = 0
    def handle_events():
        '''Typical event handling via pygame'''
        for event in pygame.event.get():
            if event.type == QUIT:
                return 0
            elif event.type == KEYUP:
                if event.key == K_ESCAPE:
                    return 0
                elif event.key == K_SPACE:
                    canvas.fill((0, 0, 0), ((0, 0), canvas.get_size()))
        return 1

    pygame.init()
    pygame.display.set_caption('Wiimote IR test')
    window = pygame.display.set_mode((cwiid.IR_X_MAX, cwiid.IR_Y_MAX), DOUBLEBUF)
    screen = pygame.display.get_surface()
    canvas = pygame.Surface(screen.get_size()) # persistent drawing here
    canvas = canvas.convert()

    wm = None # our wiimote
    clock = pygame.time.Clock()
    runing = 1
    while(runing):
        clock.tick(100)
        runing = handle_events()
        if not wm:
            wm = connect(wiimote_hwaddr)
            if not wm:
                continue
            # each message will contain info about ir and buttons
            wm.rpt_mode = cwiid.RPT_IR | cwiid.RPT_BTN # | cwiid.RPT_STATUS
            # tell cwiid to use the callback interface and allways send button events
            wm.enable(cwiid.FLAG_MESG_IFC
                      #| cwiid.FLAG_NONBLOCK
                      | cwiid.FLAG_REPEAT_BTN)

            # specify wich function will manage messages AFTER the other settings
            wm.mesg_callback = wmplugin_exec

            # quick check on the wiimote
            print "Got Wiimote!"
            st = wm.state
            for e in st:
                print str(e).ljust(8), ">", st[e]

        screen.blit(canvas, (0, 0))
        pygame.display.flip()

    if wm:
        wm.close()
else:
    #This code is used as a plugin for cwiid, we import the wminput system
    import wmplugin
    screen = None
