import pygame, sys,os
import array
from math import *
from pygame.locals import * 
import numpy
from numpy import matrix

TRANSPARENT = (255,0,255) 

X11 = (20, 40)   # (0, 0)
X21 = (620, 40)  # (1, 0)
X12 = (20, 440)  # (0, 1)
X22 = (620, 440) # (1, 1)

pygame.init()
window = pygame.display.set_mode((640, 480))
pygame.display.set_caption('Calibration')
grids = pygame.Surface((640, 480))
dots = pygame.Surface((640, 480))

def redraw():
    window.blit(grids, (0, 0))
    window.blit(dots, (0, 0))
    pygame.display.flip() 


def draw_grid(screen, f, color):
    for i in range(20, 621, 100):
        for j in range(40, 441, 4):
            pygame.draw.circle(screen, color, f((i, j)), 0)
    for i in range(40, 441, 100):
        for j in range(20, 621, 4):
            pygame.draw.circle(screen, color, f((j, i)), 0)

def id(pos):
    return pos

def test_calib(screen, f): 
    button_down = False
    print f
    while True: 
        events = pygame.event.get()
        for event in events: 
            #print event
            if event.type == QUIT: 
                sys.exit(0) 
            elif event.type == MOUSEBUTTONDOWN:
                button_down = True
                pygame.draw.circle(screen, (100, 100, 100), f(event.pos), 3)
                pygame.draw.circle(screen, (100, 255, 100), event.pos, 3)
                redraw()
            elif event.type == MOUSEBUTTONUP:
                screen.fill(TRANSPARENT)
                redraw()
                button_down = False
            elif event.type == MOUSEMOTION and button_down == True:
                pygame.draw.circle(screen, (100, 100, 100), f(event.pos), 3)
                pygame.draw.circle(screen, (100, 255, 100), event.pos, 3)
                redraw()

def get_clic():
    while True:
        events = pygame.event.get()
        for event in events: 
            if event.type == QUIT: 
                sys.exit(0) 
            if event.type == MOUSEBUTTONDOWN: 
                return event.pos

def get_points():
    dots.fill(TRANSPARENT)
    pygame.draw.circle(dots, (255, 255, 255), X11, 5, 1)
    redraw()
    Y1 = get_clic()
    print "Y1: " + str(Y1)
    dots.fill(TRANSPARENT)
    pygame.draw.circle(dots, (255, 255, 255), X21, 5, 1)
    redraw()
    Y2 = get_clic()
    print "Y2: " + str(Y2)
    dots.fill(TRANSPARENT)
    pygame.draw.circle(dots, (255, 255, 255), X12, 5, 1)
    redraw()
    Y3 = get_clic()
    print "Y3: " + str(Y3)
    dots.fill(TRANSPARENT)
    pygame.draw.circle(dots, (255, 255, 255), X22, 5, 1)
    redraw()
    Y4 = get_clic()
    print "Y4: " + str(Y4)
    dots.fill(TRANSPARENT)

    pygame.draw.line(grids, (20, 20, 150), Y1, Y2)    
    pygame.draw.line(grids, (20, 20, 150), Y2, Y4)
    pygame.draw.line(grids, (20, 20, 150), Y4, Y3)    
    pygame.draw.line(grids, (20, 20, 150), Y3, Y1)    
    redraw()

    return (Y1, Y2, Y3, Y4)

class Calibration:
    def __init__(self, Y):
        print "Y: " + str(Y)
        self.Y = Y

        x1 = Y[0][0]
        y1 = Y[0][1]
        x2 = Y[1][0]
        y2 = Y[1][1]
        x3 = Y[2][0]
        y3 = Y[2][1]
        x4 = Y[3][0]
        y4 = Y[3][1]
        X1 = X11[0]
        Y1 = X11[1]
        X2 = X21[0]
        Y2 = X21[1]
        X3 = X12[0]
        Y3 = X12[1]
        X4 = X22[0]
        Y4 = X22[1]

        A = matrix([[x1, y1, 1,  0,  0, 0, -X1 * x1, -X1 * y1],
                    [x2, y2, 1,  0,  0, 0, -X2 * x2, -X2 * y2],
                    [x3, y3, 1,  0,  0, 0, -X3 * x3, -X3 * y3],
                    [x4, y4, 1,  0,  0, 0, -X4 * x4, -X4 * y4],
                    [ 0,  0, 0, x1, y1, 1, -Y1 * x1, -Y1 * y1],
                    [ 0,  0, 0, x2, y2, 1, -Y2 * x2, -Y2 * y2],
                    [ 0,  0, 0, x3, y3, 1, -Y3 * x3, -Y3 * y3],
                    [ 0,  0, 0, x4, y4, 1, -Y4 * x4, -Y4 * y4]])

#        A = numpy.transpose(A)
        B = matrix([[ X1 ], [ X2 ], [ X3 ], [ X4 ], [ Y1 ], [ Y2 ], [ Y3 ], [ Y4 ]])
        
        h = (numpy.transpose(A) * A).I * numpy.transpose(A) * B  # here lies the real computation
        print "A: " + str(A)
        print "B: " + str(B)
        print "h: " + str(h)
        self.a = float(h[0])
        self.b = float(h[1])
        self.c = float(h[2])
        self.d = float(h[3])
        self.e = float(h[4])
        self.f = float(h[5])
        self.g = float(h[6])
        self.h = float(h[7])

    def warp(self, pos):
        x = pos[0]
        y = pos[1]
        X = (self.a * x + self.b * y + self.c) / (self.g * x + self.h * y + 1)
        Y = (self.d * x + self.e * y + self.f) / (self.g * x + self.h * y + 1)
        print (X, Y)
        return (X, Y)


def main():
    dots.fill(TRANSPARENT)
    dots.set_colorkey(TRANSPARENT)

    Y_points = get_points()
    
    draw_grid(grids, id, (100, 100, 100))
    redraw()

    cal = Calibration(Y_points)
    redraw()

    test_calib(dots, cal.warp)

if __name__ == "__main__":
    main()

