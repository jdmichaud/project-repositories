//
// matrix.hh for quaternion in 
// 
// Made by Jean-Daniel Michaud
// Login   <JeDi@epita.fr>
// 
// Started on  Fri Feb  1 15:30:10 2002 Jean-Daniel Michaud
// Last update Thu Feb 14 13:25:43 2002 jean-daniel michaud
//

#ifndef MARTIX_HH_
# define MARTIX_HH_

#include <iostream>
#include "quaternion.hh"

class Matrix : public Streamable
{
private:
  float	data[3][3];

public:
  Matrix();
  virtual ~Matrix()
  {
  }

  //  Matrix	//

  float		get(int i, int j) const;
  void		put(int i, int j, float f);

  void		print(ostream& out) const;
  void		read(istream& in);
};

Matrix		Quat2Mat(Quaternion& q);

#endif // !MARTIX_HH_
