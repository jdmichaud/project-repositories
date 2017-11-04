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
#        pygame.draw.line(screen, color, f((i, 40)), f((i, 440)))
            pygame.draw.circle(screen, color, f((i, j)), 0)
    for i in range(40, 441, 100):
        for j in range(20, 621, 4):
#        pygame.draw.line(screen, color, f((20, i)), f((620, i)))
            pygame.draw.circle(screen, color, f((j, i)), 0)

def id(pos):
    return pos

def f((x, y)):
    return (x + 20, y + 20)

def f_cal((x, y)):
    return (x - 20, y - 20)

def test_calib(screen, f): 
    button_down = False
    while True: 
        events = pygame.event.get()
        for event in events: 
#            print event
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
    V1 = (X11[0] - Y1[0], X11[1] - Y1[1])
    print "Y1: " + str(Y1)
    dots.fill(TRANSPARENT)
    pygame.draw.circle(dots, (255, 255, 255), X21, 5, 1)
    redraw()
    Y2 = get_clic()
    V2 = (X21[0] - Y2[0], X21[1] - Y2[1])
    print "Y2: " + str(Y2)
    dots.fill(TRANSPARENT)
    pygame.draw.circle(dots, (255, 255, 255), X12, 5, 1)
    redraw()
    Y3 = get_clic()
    V3 = (X12[0] - Y3[0], X12[1] - Y3[1])
    print "Y3: " + str(Y3)
    dots.fill(TRANSPARENT)
    pygame.draw.circle(dots, (255, 255, 255), X22, 5, 1)
    redraw()
    Y4 = get_clic()
    V4 = (X22[0] - Y4[0], X22[1] - Y4[1])
    print "Y4: " + str(Y4)
    dots.fill(TRANSPARENT)

    pygame.draw.line(grids, (20, 20, 150), Y1, Y2)    
    pygame.draw.line(grids, (20, 20, 150), Y2, Y4)
    pygame.draw.line(grids, (20, 20, 150), Y4, Y3)    
    pygame.draw.line(grids, (20, 20, 150), Y3, Y1)    
    redraw()

    return ((V1, V2, V3, V4), (Y1, Y2, Y3, Y4))

def init_array(n, m):
    N = n
    M = m
    mylist = []
    for i in range(N):
        mylist.append([0.0] * M)
    return mylist

def get_theta(V):
    theta = init_array(2, 2)
    print "> " + str(V)

    if (V[0][0] == 0):
        theta[0][0] = 0
    else:
        print "atan2(" + str(V[0][1]) + ", " + str(V[0][0]) + ") :" + str(atan(V[0][1]/V[0][0]))
        theta[0][0] = atan2(float(V[0][1]),float(V[0][0]))

    if (V[1][0] == 0):
        theta[1][0] = 0
    else:
        theta[1][0] = atan2(float(V[1][1]),float(V[1][0]))

    if (V[2][0] == 0):
        theta[0][1] = 0
    else:
        theta[0][1] = atan2(float(V[2][1]),float(V[2][0]))

    if (V[3][0] == 0):
        theta[1][1] = 0
    else:
        theta[1][1] = atan2(float(V[3][1]),float(V[3][0]))

    print "theta: " + str(theta)
    return theta

def get_r(V):
    r = init_array(2, 2)
    r[0][0] = sqrt(float(V[0][0]**2) + float(V[0][1]**2))
    r[1][0] = sqrt(float(V[1][0]**2) + float(V[1][1]**2))
    r[0][1] = sqrt(float(V[2][0]**2) + float(V[2][1]**2))
    r[1][1] = sqrt(float(V[3][0]**2) + float(V[3][1]**2))
    print "r: " + str(r)
    return r

class Calibration:
    def __init__(self, V, Y):
#        self.bilinear_interpolation(V)
        print "V: " + str(V)
        print "Y: " + str(Y)
        self.V = V
        self.Y = Y

        A = matrix([[Y[0][0], Y[0][1], 1, 0, 0, 0, -X11[0] * Y[0][0], -X11[0] * Y[0][1]],
                    [0, 0, 0, Y[0][0], Y[0][1], 1, -X11[1] * Y[0][0], -X11[1] * Y[0][1]],
                    [Y[1][0], Y[1][1], 1, 0, 0, 0, -X12[0] * Y[1][0], -X12[0] * Y[1][1]],
                    [0, 0, 0, Y[1][0], Y[1][1], 1, -X12[1] * Y[1][0], -X12[1] * Y[1][1]],
                    [Y[2][0], Y[2][1], 1, 0, 0, 0, -X21[0] * Y[2][0], -X21[0] * Y[2][1]],
                    [0, 0, 0, Y[2][0], Y[2][1], 1, -X21[1] * Y[2][0], -X21[1] * Y[2][1]],
                    [Y[3][0], Y[3][1], 1, 0, 0, 0, -X22[0] * Y[3][0], -X11[0] * Y[3][1]],
                    [0, 0, 0, Y[3][0], Y[3][1], 1, -X22[1] * Y[3][0], -X22[1] * Y[3][1]]])
        
        B = matrix([[ X11[0] ], [ X11[1] ], [ X12[0] ], [ X12[1] ], [ X21[0] ], [ X21[1] ], [ X22[0] ], [ X22[1] ]])
        
        
        h = (numpy.transpose(A) * A).I * numpy.transpose(A) * B
        print "A: " + str(A)
        print "B: " + str(B)
        print "h: " + str(h)
        self.a = h[0]
        self.b = h[1]
        self.c = h[2]
        self.d = h[3]
        self.e = h[4]
        self.f = h[5]
        self.g = h[6]


    def point_line_distance(self, point, line):
        #http://mathworld.wolfram.com/Point-LineDistance2-Dimensional.htm
        x0 = point[0]
        x1 = line[0][0]
        x2 = line[1][0]
        y0 = point[1]
        y1 = line[0][1]
        y2 = line[1][1]

        return float(abs((x2 - x1) * (y1 - y0) - (x1 - x0) * (y2 - y1))) / sqrt((x2 - x1)**2 + (y2 - y1)**2)

    def my_dist(self, ref_point, point, opposite_line1, opposite_line2):
        # http://mathworld.wolfram.com/Point-LineDistance2-Dimensional.html

        d1 = self.point_line_distance(ref_point, opposite_line1)
        d2 = self.point_line_distance(ref_point, opposite_line2)
        dprime1 = self.point_line_distance(point, opposite_line1)
        dprime2 = self.point_line_distance(point, opposite_line2)

        return (1 - (float(d1 - dprime1) / d1)) * ((1 - (float(d2 - dprime2) / d2)))
        

    def my_interpolation(self, V, Y):
        self.x_shift = init_array(640, 480)
        self.y_shift = init_array(640, 480)
        for x in range(1, 640):
            for y in range(1, 480):
                k11 = self.my_dist(Y[0], (x, y), (Y[1], Y[3]), (Y[2], Y[3]))
                k21 = self.my_dist(Y[2], (x, y), (Y[0], Y[1]), (Y[3], Y[1]))
                k12 = self.my_dist(Y[1], (x, y), (Y[0], Y[2]), (Y[3], Y[2]))
                k22 = self.my_dist(Y[3], (x, y), (Y[2], Y[0]), (Y[1], Y[0]))
                #print "k11: " + str(k11) + "k21: " + str(k21) + "k12: " + str(k12) + "k22: " + str(k22)
                self.x_shift[x][y] = float(V[0][0] * k11 + V[1][0] * k12 + V[2][0] * k21 + V[3][0] * k22)
                self.y_shift[x][y] = float(V[0][1] * k11 + V[1][1] * k12 + V[2][1] * k21 + V[3][1] * k22)
                #print "x_shift: " + str(self.x_shift[x][y]) + " - y_shift: " + str(self.y_shift[x][y])

    def bilinear_interpolation(self, V): 
        r = get_r(V)
        theta = get_theta(V)
        self.cal_r = init_array(640, 480)
        self.cal_theta = init_array(640, 480)
        x1 = float(20)
        x2 = float(620)
        y1 = float(40)
        y2 = float(440)

        for x in range(1, 640):
            for y in range(1, 480):
                self.cal_r[x][y] =  r[0][0] / ((x2 - x1) * (y2 - y1)) * (x2 - x) * (y2 - y) + r[1][0] / ((x2 - x1) * (y2 - y1)) * (x - x1) * (y2 - y) + r[0][1] / ((x2 - x1) * (y2 - y1)) * (x2 - x) * (y - y1) + r[1][1] / ((x2 - x1) * (y2 - y1)) * (x - x1) * (y - y1)
                self.cal_theta[x][y] = theta[0][0] / ((x2 - x1) * (y2 - y1)) * (x2 - x) * (y2 - y) + theta[1][0] / ((x2 - x1) * (y2 - y1)) * (x - x1) * (y2 - y) + theta[0][1] / ((x2 - x1) * (y2 - y1)) * (x2 - x) * (y - y1) + theta[1][1] / ((x2 - x1) * (y2 - y1)) * (x - x1) * (y - y1)

#    def bicubic_interpolation(self, r, theta):
        

    def f(self, pos):
        x = pos[0]
        y = pos[1]
        X = (a * x + b * y + c) / (g * x + h * y + 1)
        Y = (d * x + e * y + f) / (g * x + h * y + 1)
        return (X, Y)

    def f_inv(self, pos):
        r = self.cal_r[pos[0]][pos[1]]
        theta = self.cal_theta[pos[0]][pos[1]]
        x = r * cos(theta)
        y = r * sin(theta)
        res = (pos[0] + x, pos[1] + y)
        return res

    def f2(self, pos):
        print "pos: " + str(pos)
        print "V: " + str(self.V)
        print "Y: " + str(self.Y)
        Y = self.Y
        print "k11: " + str(self.my_dist(Y[0], pos, (Y[1], Y[3]), (Y[2], Y[3])))
        print "k21: " + str(self.my_dist(Y[2], pos, (Y[0], Y[1]), (Y[3], Y[1])))
        print "k12: " + str(self.my_dist(Y[1], pos, (Y[0], Y[2]), (Y[3], Y[2])))
        print "k22: " + str(self.my_dist(Y[3], pos, (Y[2], Y[0]), (Y[1], Y[0])))

        y = (pos[0] + self.x_shift[pos[0]][pos[1]],
             pos[1] + self.y_shift[pos[0]][pos[1]])
        print "y: " + str(y)
        return y

    def f2_inv(self, pos):
        return (pos[0] - self.x_shift[pos[0]][pos[1]],
                pos[1] - self.y_shift[pos[0]][pos[1]])

class johnny:
    def __init__(self, X, Y):
        srcMat = self.computeQuadToSquare(Y)
        dstMat = self.computeSquareToQuad(X)
        self.warpMat = matrix(srcMat) * matrix(dstMat)

    def computeSquareToQuad(self, points):
        ((x0, y0), (x1, y1), (x2, y2), (x3, y3)) = points
        dx1 = float(x1 - x2)
        dy1 = float(y1 - y2)
        dx2 = float(x3 - x2)
        dy2 = float(y3 - y2)
        sx = float(x0 - x1 + x2 - x3)
        sy = float(y0 - y1 + y2 - y3)
        g = (sx * dy2 - sy * dx2) / (dx1 * dy2 - dx2 * dy1)
        h = (sy * dx1 - sx * dy1) / (dx1 * dy2 - dx2 * dy1)
        a = x1 - x0 + g * x1
        b = x3 - x0 + h * x3
        c = x0
        d = y1 - y0 + g * y1
        e = y3 - y0 + h * y3
        f = y0

        result = init_array(4, 4)
        result[0][0] = a
        result[0][1] = d
        result[0][2] = 0
        result[0][3] = g

        result[1][0] = b
        result[1][1] = e
        result[1][2] = 0
        result[1][3] = h

        result[2][0] = 0
        result[2][1] = 0
        result[2][2] = 1
        result[2][3] = 0

        result[3][0] = c
        result[3][1] = f
        result[3][2] = 0
        result[3][3] = 1
        return result

    def computeQuadToSquare(self, points):
        mat = self.computeSquareToQuad(points)
        ((x0, y0), (x1, y1), (x2, y2), (x3, y3)) = points

        a = mat[0][0]
        d = mat[0][1]
        g = mat[0][3]
        b = mat[1][0]
        e = mat[1][1]
        h = mat[1][3]
        c = mat[3][0]
        f = mat[3][1]

        A =     e - f * h;
        B = c * h - b;
        C = b * f - c * e;
        D = f * g - d;
        E =     a - c * g;
        F = c * d - a * f;
        G = d * h - e * g;
        H = b * g - a * h;
        I = a * e - b * d;
        
        idet = 1.0 / (a * A + b * D + c * G);

        result = init_array(4, 4)
        result[0][0] = A * idet
        result[0][1] = D * idet
        result[0][2] = 0
        result[0][3] = G * idet

        result[1][0] = B * idet
        result[1][1] = E * idet
        result[1][2] = 0
        result[1][3] = H * idet

        result[2][0] = 0
        result[2][1] = 0
        result[2][2] = 1
        result[2][3] = 0

        result[3][0] = C * idet
        result[3][1] = F * idet
        result[3][2] = 0
        result[3][3] = I * idet
        return result
        

    def warp(self, pos):
        result = [0.0, 0.0, 0.0, 0.0]
        z = 0.0
        result[0] = pos[0] * self.warpMat.A[0][0] + pos[1] * self.warpMat.A[1][0] + z * self.warpMat.A[2][0] + 1 * self.warpMat.A[3][0]
        result[1] = pos[0] * self.warpMat.A[0][1] + pos[1] * self.warpMat.A[1][1] + z * self.warpMat.A[2][1] + 1 * self.warpMat.A[3][1]
        result[2] = pos[0] * self.warpMat.A[0][2] + pos[1] * self.warpMat.A[1][2] + z * self.warpMat.A[2][2] + 1 * self.warpMat.A[3][2]
        result[3] = pos[0] * self.warpMat.A[0][3] + pos[1] * self.warpMat.A[1][3] + z * self.warpMat.A[2][3] + 1 * self.warpMat.A[3][3]
        return (result[0] / result[3], result[1] / result[3])

def main():
    dots.fill(TRANSPARENT)
    dots.set_colorkey(TRANSPARENT)

    (V_vectors, Y_points) = get_points()
    
    draw_grid(grids, id, (100, 100, 100))
    redraw()

#    cal = Calibration(V_vectors, Y_points)
    cal = johnny((X11, X21, X12, X22), Y_points)
    #draw_grid(grids, cal.f2_inv, (100, 255, 100))
    redraw()

    test_calib(dots, cal.warp)

if __name__ == "__main__":
    main()

