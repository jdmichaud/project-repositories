#ifndef __CALIBRATE_H__
#define __CALIBRATE_H__

extern float *g_warpMat;
extern int g_calibrated;

void computeSquareToQuad(float x0,
                         float y0,
                         float x1,
                         float y1,
                         float x2,
                         float y2,
                         float x3,
                         float y3,
                         float *mat);

void computeQuadToSquare(float x0,
                         float y0,
                         float x1,
                         float y1,
                         float x2,
                         float y2,
                         float x3,
                         float y3,
                         float *mat);

void multMats(float *srcMat, float *dstMat, float *resMat);
void computeWarp(float *srcX, float *srcY, 
                 float *dstX, float *dstY, 
                 float *warpMat);

void calibrate();
void warp(int srcX, int srcY, int *dstX, int *dstY);

#endif // __CALIBRATE_H__
