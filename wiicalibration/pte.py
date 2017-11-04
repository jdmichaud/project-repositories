import pygame, sys,os
import array
from math import *
from pygame.locals import *

import scipy
from scipy.linalg import inv, det, eig
from scipy import matrix

TRANSPARENT = (255,0,255)

Xp=matrix([[20], [20], [620], [620]])
Yp=matrix([[40], [440], [440], [40]])

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
                screen.fill(TRANSPARENT)
                pygame.draw.circle(screen, (100, 100, 100), f(event.pos), 3)
                pygame.draw.circle(screen, (100, 255, 100), event.pos, 3)
                redraw()
            elif event.type == MOUSEBUTTONUP:
#                screen.fill(TRANSPARENT)
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
    pygame.draw.circle(dots, (255, 255, 255), (Xp[0], Yp[0]), 5, 1)
    redraw()
    Y1 = get_clic()
    print "Y1: " + str(Y1)
    dots.fill(TRANSPARENT)
    pygame.draw.circle(dots, (255, 255, 255), (Xp[1], Yp[1]), 5, 1)
    redraw()
    Y2 = get_clic()
    print "Y2: " + str(Y2)
    dots.fill(TRANSPARENT)
    pygame.draw.circle(dots, (255, 255, 255), (Xp[2], Yp[2]), 5, 1)
    redraw()
    Y3 = get_clic()
    print "Y3: " + str(Y3)
    dots.fill(TRANSPARENT)
    pygame.draw.circle(dots, (255, 255, 255), (Xp[3], Yp[3]), 5, 1)
    redraw()
    Y4 = get_clic()
    print "Y4: " + str(Y4)
    dots.fill(TRANSPARENT)

    pygame.draw.line(grids, (20, 20, 150), Y1, Y2)
    pygame.draw.line(grids, (20, 20, 150), Y2, Y3)
    pygame.draw.line(grids, (20, 20, 150), Y3, Y4)
    pygame.draw.line(grids, (20, 20, 150), Y4, Y1)
    redraw()

    return (Y1, Y2, Y3, Y4)

class Calibration:
    def __init__(self):
        pass

    def compute_pte(self, X, Y, Xp, Yp):
        X=X/640.0
        Y=Y/640.0
        Xp=Xp/640.0
        Yp=Yp/640.0
        B = matrix( [[float(X[0]), Y[0], 1, 0, 0, 0, -X[0] * Xp[0], -Y[0] * Xp[0]],
                     [float(X[1]), Y[1], 1, 0, 0, 0, -X[1] * Xp[1], -Y[1] * Xp[1]],
                     [float(X[2]), Y[2], 1, 0, 0, 0, -X[2] * Xp[2], -Y[2] * Xp[2]],
                     [float(X[3]), Y[3], 1, 0, 0, 0, -X[3] * Xp[3], -Y[3] * Xp[3]],
                     [0, 0, 0, X[0], Y[0], 1, -X[0] * Yp[0], -Y[0] * Yp[0]],
                     [0, 0, 0, X[1], Y[1], 1, -X[1] * Yp[1], -Y[1] * Yp[1]],
                     [0, 0, 0, X[2], Y[2], 1, -X[2] * Yp[2], -Y[2] * Yp[2]],
                     [0, 0, 0, X[3], Y[3], 1, -X[3] * Yp[3], -Y[3] * Yp[3]]] )

        D = matrix( [[float(Xp[0])], [float(Xp[1])], [float(Xp[2])], [float(Xp[3])], [float(Yp[0])], [float(Yp[1])], [float(Yp[2])], [float(Yp[3])]] )
        print "B: "
        print str(B)
        print "D: "
        print str(D)
        self.l = inv(B.T * B) * B.T * D
  

    def warp(self, pos):
        x=pos[0]/640.0
        y=pos[1]/640.0
        l=self.l
        A = matrix([ float(l[0:6][0]), l[0:6][1], l[0:6][2], l[0:6][3], l[0:6][4], l[0:6][5], 0, 0, 1 ])
        A = A.reshape(3, 3)
        #print "A: "
        #print str(A)
        C = matrix([ float(l[6]), l[7], 1 ])
        #print "C: "
        #print str(C)
        t = A * matrix([[x], [y], [1]]) / (C * matrix([[x], [y], [1]]))
        return (t[0]*640, t[1]*640)

def main():
    dots.fill(TRANSPARENT)
    dots.set_colorkey(TRANSPARENT)

    Y_points = get_points()
    
    draw_grid(grids, id, (100, 100, 100))
    redraw()

    cal = Calibration()
    # build calibration points as matrices of Xs and Ys
    X = matrix([ [float(Y_points[0][0])], [Y_points[1][0]], [Y_points[2][0]], [Y_points[3][0]] ])
    Y = matrix([ [float(Y_points[0][1])], [Y_points[1][1]], [Y_points[2][1]], [Y_points[3][1]] ])

    cal.compute_pte(X, Y, Xp, Yp)
    redraw()

    test_calib(dots, cal.warp)

if __name__ == "__main__":
    main()


#Xp=matrix([[0], [0], [640], [640]])
#Yp=matrix([[0], [480], [480], [0]])
#X=matrix([[120], [240], [508], [532]])
#Y=matrix([[240], [373], [334], [190]])
#(l, B, D) = compute_pte(X, Y, Xp, Yp)
#print str(warp(l, 300, 300))
