//
// slerp.cc for quaternion in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Thu Feb  7 13:54:26 2002 jean-daniel michaud
// Last update Thu Feb 14 18:11:23 2002 jean-daniel michaud
//

#include <iostream>
#include <math.h>
#include <assert.h>
#include "slerp.hh"

// Si Omega = 0. Dl de la formule au rang 1

Quaternion	slerp(Quaternion& q, Quaternion& p, float h)
{
  float		omega;

  q.normalize();
  p.normalize();
  assert((h >= 0) && (h <= 1));
  omega = acosf(q.getW() * p.getW() + q.getX() * p.getX() 
		+ q.getY() * p.getY() + q.getZ() * p.getZ());
  if (omega != 0.)
    return ((q * sinf((1 - h) * omega) + p * sinf(h * omega)) 
	    * (1 / (sinf(omega))));
  return (q * (1 - h) + p * h);
}
