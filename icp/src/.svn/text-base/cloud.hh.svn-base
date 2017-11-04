//
// could.hh for math in math
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sun May 19 17:14:55 2002 jean-daniel michaud
//

#ifndef CLOUD_HH_
# define CLOUD_HH_

#include <vector>
#include <GL/glut.h>
#include "object.hh"
#include "opengl.hh"
#include "vector.hh"

extern int verbose_p;

class Cloud : public Object
{
public:
  Cloud () {}
  Cloud (vector<Vector3D> vect)  
  {
    _points = vect;
  }

  vector<Vector3D>& translate(const Vector3D& vect)
  {
    std::vector<Vector3D>::iterator i;

    std::cout << "Translation en cours : ";
    for (i = _points.begin(); i != _points.end(); ++i)
      {
	i->setX (i->getX() + vect.getX());
	i->setY (i->getY() + vect.getY());
	i->setZ (i->getZ() + vect.getZ());
      }
    std::cout << " OK " << std::endl;
  }
  
  void		complexify (void)
  {
    vector<Vector3D> baries;
    Vector3D	bary;

    if (verbose_p)
      cout << "complexifing cloud" << endl;
    for (unsigned i = 0; i < _points.size (); ++i)
      {
	bary = (_points[i] + _points[_points[i].getNearest (_points)]) / 2;
	baries.push_back (bary);
      }
    for (unsigned i = 0; i < baries.size (); ++i)
      _points.push_back (baries[i]);
  }

};

#endif 
