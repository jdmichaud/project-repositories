//
// slerp.hh for quaternion in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Thu Feb  7 13:54:45 2002 jean-daniel michaud
// Last update Thu Feb  7 15:33:53 2002 jean-daniel michaud
//

#ifndef SLERP_HH_
# define SLERP_HH_

#include "quaternion.hh"

Quaternion	slerp(Quaternion &q, Quaternion &p, float h);

#endif // !SLERP_HH_
