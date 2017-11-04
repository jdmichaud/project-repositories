
#include <unistd.h>
#include <stdlib.h>

#include "calibrate.h"
#include "xdrive.h"
#include "wiimote.h"

float *g_warpMat;
int g_calibrated;

void computeSquareToQuad(float x0,
                         float y0,
                         float x1,
                         float y1,
                         float x2,
                         float y2,
                         float x3,
                         float y3,
                         float *mat)
{
  float dx1 = x1 - x2,  dy1 = y1 - y2;
  float dx2 = x3 - x2,  dy2 = y3 - y2;
  float sx = x0 - x1 + x2 - x3;
  float sy = y0 - y1 + y2 - y3;
  float g = (sx * dy2 - dx2 * sy) / (dx1 * dy2 - dx2 * dy1);
  float h = (dx1 * sy - sx * dy1) / (dx1 * dy2 - dx2 * dy1);
  float a = x1 - x0 + g * x1;
  float b = x3 - x0 + h * x3;
  float c = x0;
  float d = y1 - y0 + g * y1;
  float e = y3 - y0 + h * y3;
  float f = y0;

  mat[ 0] = a;  mat[ 1] = d;  mat[ 2] = 0;  mat[ 3] = g;
  mat[ 4] = b;  mat[ 5] = e;  mat[ 6] = 0;  mat[ 7] = h;
  mat[ 8] = 0;  mat[ 9] = 0;  mat[10] = 1;  mat[11] = 0;
  mat[12] = c;  mat[13] = f;  mat[14] = 0;  mat[15] = 1;
}

void computeQuadToSquare(  float x0,
                           float y0,
                           float x1,
                           float y1,
                           float x2,
                           float y2,
                           float x3,
                           float y3,
                           float *mat)
{
  computeSquareToQuad(x0,y0,x1,y1,x2,y2,x3,y3, mat);

  // invert through adjoint

  float a = mat[ 0],  d = mat[ 1],  /* ignore */    g = mat[ 3];
  float b = mat[ 4],  e = mat[ 5],  /* 3rd col*/    h = mat[ 7];
  /* ignore 3rd row */
  float c = mat[12],  f = mat[13];
  float A =     e - f * h;
  float B = c * h - b;
  float C = b * f - c * e;
  float D = f * g - d;
  float E =     a - c * g;
  float F = c * d - a * f;
  float G = d * h - e * g;
  float H = b * g - a * h;
  float I = a * e - b * d;

  // Probably unnecessary since 'I' is also scaled by the determinant,
  //   and 'I' scales the homogeneous coordinate, which, in turn,
  //   scales the X,Y coordinates.
  // Determinant  =   a * (e - f * h) + b * (f * g - d) + c * (d * h - e * g);
  float idet = 1.0f / (a * A           + b * D           + c * G);

  mat[ 0] = A * idet; mat[ 1] = D * idet; mat[ 2] = 0;  mat[ 3] = G * idet;
  mat[ 4] = B * idet; mat[ 5] = E * idet; mat[ 6] = 0;  mat[ 7] = H * idet;
  mat[ 8] = 0       ; mat[ 9] = 0       ; mat[10] = 1;  mat[11] = 0       ;
  mat[12] = C * idet; mat[13] = F * idet; mat[14] = 0;  mat[15] = I * idet;
}

void multMats(float *srcMat, float *dstMat, float *resMat)
{
  // DSTDO/CBB: could be faster, but not called often enough to matter
  int r = 0;
  for (r = 0; r < 4; r++) {
    int ri = r * 4;
    int c = 0;
    for (c = 0; c < 4; c++) {
      resMat[ri + c] = (srcMat[ri    ] * dstMat[c     ] +
                        srcMat[ri + 1] * dstMat[c +  4] +
                        srcMat[ri + 2] * dstMat[c +  8] +
                        srcMat[ri + 3] * dstMat[c + 12]);
    }
  }
}

void computeWarp(float *srcX, float *srcY, 
                 float *dstX, float *dstY, 
                 float *warpMat)
{
  float *srcMat = (float *) malloc(sizeof (float) * 16);
  float *dstMat = (float *) malloc(sizeof (float) * 16);
  if (warpMat == NULL)
    warpMat = (float *) malloc(sizeof (float) * 16);

  computeQuadToSquare(  srcX[0],srcY[0],
                        srcX[1],srcY[1],
                        srcX[2],srcY[2],
                        srcX[3],srcY[3],
                        srcMat);
  computeSquareToQuad(  dstX[0], dstY[0],
                        dstX[1], dstY[1],
                        dstX[2], dstY[2],
                        dstX[3], dstY[3],
                        dstMat);
  multMats(srcMat, dstMat, warpMat);
  free(srcMat);
  free(dstMat);
}

void calibrate()
{
  int x, y;
  float *srcX = (float *) malloc(sizeof (float) * 4);
  float *srcY = (float *) malloc(sizeof (float) * 4);
  float *dstX = (float *) malloc(sizeof (float) * 4);
  float *dstY = (float *) malloc(sizeof (float) * 4);

  mousemove(20, 20);
  read(g_pipefd[0], &x, sizeof (x));
  read(g_pipefd[0], &y, sizeof (y));
  printf("x: %i - y: %i", x, y);
  srcX[0] = 20;
  srcY[0] = 20;
  dstX[0] = x;
  dstY[0] = y;

  mousemove(20, 1030);
  read(g_pipefd[0], &x, sizeof (x));
  read(g_pipefd[0], &y, sizeof (y));
  printf("x: %i - y: %i", x, y);
  srcX[1] = 20;
  srcY[1] = 1030;
  dstX[1] = x;
  dstY[1] = y;

  mousemove(1360, 20);
  read(g_pipefd[0], &x, sizeof (x));
  read(g_pipefd[0], &y, sizeof (y));
  printf("x: %i - y: %i", x, y);
  srcX[2] = 1360;
  srcY[2] = 20;
  dstX[2] = x;
  dstY[2] = y;

  mousemove(1360, 1030);
  read(g_pipefd[0], &x, sizeof (x));
  read(g_pipefd[0], &y, sizeof (y));
  printf("x: %i - y: %i", x, y);
  srcX[3] = 1360;
  srcY[3] = 1030;
  dstX[3] = x;
  dstY[3] = y;

  computeWarp(srcX, srcY, dstX, dstY, g_warpMat);

  g_calibrated = 1;
}

void warp(int srcX, int srcY, int *dstX, int *dstY)
{
  float result[4];
  float z = 0;
  result[0] = (float)(srcX * g_warpMat[0] + srcY*g_warpMat[4] + z*g_warpMat[8] + 1*g_warpMat[12]);
  result[1] = (float)(srcX * g_warpMat[1] + srcY*g_warpMat[5] + z*g_warpMat[9] + 1*g_warpMat[13]);
  result[2] = (float)(srcX * g_warpMat[2] + srcY*g_warpMat[6] + z*g_warpMat[10] + 1*g_warpMat[14]);
  result[3] = (float)(srcX * g_warpMat[3] + srcY*g_warpMat[7] + z*g_warpMat[11] + 1*g_warpMat[15]);
  *dstX = result[0]/result[3];
  *dstY = result[1]/result[3];
}


