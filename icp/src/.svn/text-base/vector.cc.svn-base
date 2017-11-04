//
// vector.cc for  in 
// 
// Made by GIZMO
// Login   <grimau_r@epita.fr>
// 
// Started on  Mon Feb  4 17:37:15 2002 GIZMO
// Last update Mon May 20 11:40:56 2002 GIZMO
//

#include "vector.hh"

//--- constructeurs ---
Vector3D::Vector3D()
{
  this->tab[0] = 0;
  this->tab[1] = 0;
  this->tab[2] = 0;
}

Vector3D::Vector3D(double x, double y, double z)
{
  this->tab[0] = x;
  this->tab[1] = y;
  this->tab[2] = z;
  
  //  std::cout << "x = " << x << " y = " << y << " z = " << z << std::endl;//
}

std::ostream& operator<< (std::ostream& os, const Vector3D& vect)
{
  vect.print(os);
  return (os);
}
