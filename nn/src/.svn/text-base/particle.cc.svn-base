#include <stdlib.h>
#include "particle.hh"

double random(double min, double max)
{
  double i = rand();
  i = (i * (max - min)) / RAND_MAX;
  return i + min;
}

double constrict(double delta, double deltaMin, double deltaMax)
{
  if (delta < deltaMin)
    return deltaMin;
  else if (delta > deltaMax)
    return deltaMax;
  else
    return delta;
}
