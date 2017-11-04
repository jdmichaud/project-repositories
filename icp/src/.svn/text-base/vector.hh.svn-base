//
// vector.hh for  in 
// 
// Made by GIZMO
// Login   <grimau_r@epita.fr>
// 
// Started on  Mon Feb  4 17:10:57 2002 GIZMO
// Last update Tue May 28 15:19:24 2002 jean-daniel michaud
//

#ifndef VECTOR_HH
# define VECTOR_HH

using namespace std;

#include <math.h>
#include <iostream>
#include <vector>

class Matrix;

class Vector3D
{
public:
  // constructeurs
  Vector3D();
  Vector3D(double x, double y, double z);
  
  // accesseurs
  double  getX() const { return tab[0]; }
  double  getY() const { return tab[1]; }
  double  getZ() const { return tab[2]; }
  void  setX(double x) { tab[0] = x; }
  void  setY(double y) { tab[1] = y; }
  void  setZ(double z) { tab[2] = z; }
  
  void  print(std::ostream& os) const
  {
    os << tab[0] << " " << tab[1] << " " << tab[2];
  }
  
  Vector3D  operator+ (const Vector3D v2) const
  {
    Vector3D res;
    
    res.setX (this->getX () + v2.getX ());
    res.setY (this->getY () + v2.getY ());
    res.setZ (this->getZ () + v2.getZ ());
    return res;
  }
  
  Vector3D  operator- (const Vector3D v2) const
  {
    Vector3D res;
    
    res.setX (this->getX () - v2.getX ());
    res.setY (this->getY () - v2.getY ());
    res.setZ (this->getZ () - v2.getZ ());
    return res;
  }

  Vector3D  operator/ (int div) const
  {
    Vector3D res;
    
    res.setX (this->getX () / div);
    res.setY (this->getY () / div);
    res.setZ (this->getZ () / div);
    return res;
  }

  
  double norme(void) const
  {
    return (sqrt (tab[0] * tab[0] +
		  tab[1] * tab[1] +
		  tab[2] * tab[2]));
  }
  
  double norme_opti(void) const
  {
    return (tab[0] * tab[0] +
	    tab[1] * tab[1] +
	    tab[2] * tab[2]);
  }  

  unsigned int getNearest(const vector<Vector3D>& pgmPoints) const
  {
    Vector3D res;
    unsigned pos = 0;
    double min;
    double tmp;

    res = *this - pgmPoints[0];
    min = res.norme_opti ();
    for (unsigned i = 1; i < pgmPoints.size (); ++i)
      {
	res = *this - pgmPoints[i];
	tmp = res.norme_opti ();
	if (tmp < min)
	  {
	    pos = i;
	    min = tmp;
	  }
      }
   return pos;
  }
  
  double tab[3];
private:
};

std::ostream& operator<< (std::ostream& os, const Vector3D& vect);

#endif // end VECTOR_HH
