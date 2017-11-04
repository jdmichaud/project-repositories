//
// matrix.cc for quaternion in 
// 
// Made by Jean-Daniel Michaud
// Login   <JeDi@epita.fr>
// 
// Started on  Fri Feb  1 15:31:31 2002 Jean-Daniel Michaud
// Last update Thu Feb 14 18:12:12 2002 jean-daniel michaud
//

#include <assert.h>
#include "matrix.hh"

// Constructeur

Matrix::Matrix()
{
  int		i;
  int		j;

  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      put(i, j, 0);
}

// Methodes d'encapsulation

float		Matrix::get(int i, int j) const
{
  assert((i < 3) & (i >= 0) && (j < 3) && (j >= 0));
  return (data[i][j]);
}

void		Matrix::put(int i, int j, float f)
{
  assert((i < 3) & (i >= 0) && (j < 3) && (j >= 0));
  data[i][j] = f;
}

// Methodes d'E/S

void	        Matrix::print(ostream& out) const
{
  int		i;
  int		j;

  for (i = 0; i < 3; ++i)
    {
      for (j = 0; j < 3; ++j)
	{
	  out << data[i][j];
	  if (j < 2)
	    out << " ";
	}
      if (i < 2)
	out << endl;
    }
  out << endl;
}

void		Matrix::read(istream& in)
{
  int		i;
  int		j;

  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      in >> data[i][j];
}

//
// Conversion Quaternion -> Matrix
//

Matrix		Quat2Mat(Quaternion& q)
{
  Matrix	m;

  q.normalize();
  m.put(0, 0, 1 - 2 * (q.getY() * q.getY()) - 2 * (q.getZ() * q.getZ()));
  m.put(0, 1, 2 * q.getX() * q.getY() - 2 * q.getZ() * q.getW());
  m.put(0, 2, 2 * q.getX() * q.getZ() + 2 * q.getY() * q.getW());
  m.put(1, 0, 2 * q.getX() * q.getY() + 2 * q.getZ() * q.getW());
  m.put(1, 1, 1 - 2 * (q.getX() * q.getX()) - 2 * (q.getZ() * q.getZ()));
  m.put(1, 2, 2 * q.getY() * q.getZ() - 2 * q.getX() * q.getW());
  m.put(2, 0, 2 * q.getX() * q.getZ() - 2 * q.getY() * q.getW());
  m.put(2, 1, 2 * q.getY() * q.getZ() + 2 * q.getX() * q.getW());
  m.put(2, 2, 1 - 2 * (q.getX() * q.getX()) - 2 * (q.getY() * q.getY()));
  return (m);
}
