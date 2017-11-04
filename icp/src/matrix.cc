//
// matrix.cc for  in 
// 
// Made by GIZMO
// Login   <grimau_r@epita.fr>
// 
// Started on  Mon Feb  4 15:52:09 2002 GIZMO
// Last update Wed May 29 08:53:51 2002 jean-daniel michaud
//

#include <iostream>

#include "streamable.hh"
#include "quaternion.hh"
#include "matrix.hh"

//--- constructeurs ---
Matrix::Matrix() : Streamable()
{
  this->tab[0][0] = 0;
  this->tab[0][1] = 0;
  this->tab[0][2] = 0;
  
  this->tab[1][0] = 0;
  this->tab[1][1] = 0;
  this->tab[1][2] = 0;
  
  this->tab[2][0] = 0;
  this->tab[2][1] = 0;
  this->tab[2][2] = 0;
}

Matrix::Matrix(double m00, double m01, double m02,
	       double m10, double m11, double m12,
	       double m20, double m21, double m22) : Streamable()
{
  this->tab[0][0] = m00;
  this->tab[0][1] = m01;
  this->tab[0][2] = m02;
  
  this->tab[1][0] = m10;
  this->tab[1][1] = m11;
  this->tab[1][2] = m12;
  
  this->tab[2][0] = m20;
  this->tab[2][1] = m21;
  this->tab[2][2] = m22;
}

//--- operations ---
Vector3D& Matrix::operator* (const Vector3D& vect) const
{
  Vector3D* v = new Vector3D();

  v->setX(this->tab[0][0] * vect.getX() +
	  this->tab[0][1] * vect.getY() +
	  this->tab[0][2] * vect.getZ());
  v->setY(this->tab[1][0] * vect.getX() +
	  this->tab[1][1] * vect.getY() +
	  this->tab[1][2] * vect.getZ());
  v->setZ(this->tab[2][0] * vect.getX() +
	  this->tab[2][1] * vect.getY() +
	  this->tab[2][2] * vect.getZ());
  return *v;
}

Matrix Matrix::transpose (void) const
{
  Matrix res (tab[0][0], tab[1][0], tab[2][0],
	      tab[0][1], tab[1][1], tab[2][1],
	      tab[0][2], tab[1][2], tab[2][2]);

  return res;
}

//--- methodes ---
void Matrix::print(ostream& os) const
{
  os << this->tab[0][0] << " " << this->tab[0][1] << " " << this->tab[0][2]
     << std::endl << this->tab[1][0] << " " << this->tab[1][1] << " "
     << this->tab[1][2] << std::endl << this->tab[2][0] << " "
     << this->tab[2][1] << " " << this->tab[2][2] << std::endl;
}

void Matrix::read(istream& is)
{
  is >> this->tab[0][0];
}

//-- fonctions de conversion --- 
Matrix quat2mat(const Quaternion& quat)
{
  double w = quat.getW();
  double x = quat.getX();
  double y = quat.getY();
  double z = quat.getZ();
  
  return (Matrix(1 - 2 * y * y - 2 * z * z,
		 2 * x * y - 2 * z * w,
		 2 * x * z + 2 * y * w,
		 
		 2 * x * y + 2 * z * w,
		 1 - 2 * x * x - 2 * z * z,
		 2 * y * z - 2 * x * w,
		 
		 2 * x * z - 2 * y * w,
		 2 * y * z + 2 * x * w,
		 1 - 2 * x * x - 2 * y * y));
}


Matrix  operator* (const Vector3D v1, const Vector3D v2)
{
  Matrix	res (v1.getX () * v2.getX (),
		     v1.getX () * v2.getY (),
		     v1.getX () * v2.getZ (),
		     v1.getY () * v2.getX (),
		     v1.getY () * v2.getY (),
		     v1.getY () * v2.getZ (),
		     v1.getZ () * v2.getX (),
		     v1.getZ () * v2.getY (),
		     v1.getZ () * v2.getZ ());
  
  return res;
}

Matrix Matrix::operator/ (double div) const
{
  Matrix res (tab[0][0] / div, tab[0][1] / div, tab[0][2] / div,
	      tab[1][0] / div, tab[1][1] / div, tab[1][2] / div,
	      tab[2][0] / div, tab[2][1] / div, tab[2][2] / div);
  
  return res;
}

Matrix Matrix::operator* (double div) const
{
  Matrix res (tab[0][0] * div, tab[0][1] * div, tab[0][2] * div,
	      tab[1][0] * div, tab[1][1] * div, tab[1][2] * div,
	      tab[2][0] * div, tab[2][1] * div, tab[2][2] * div);
  
  return res;
}

Matrix Matrix::operator+ (const Matrix& m2) const
{
  Matrix res(tab[0][0] + m2.tab[0][0], 
	     tab[0][1] + m2.tab[0][1], 
	     tab[0][2] + m2.tab[0][2],
	     tab[1][0] + m2.tab[1][0], 
	     tab[1][1] + m2.tab[1][1], 
	     tab[1][2] + m2.tab[1][2],
	     tab[2][0] + m2.tab[2][0], 
	     tab[2][1] + m2.tab[2][1], 
	     tab[2][2] + m2.tab[2][2]);

  return res;
}

Matrix Matrix::operator- (const Matrix& m2) const
{
  Matrix res(tab[0][0] - m2.tab[0][0], 
	     tab[0][1] - m2.tab[0][1], 
	     tab[0][2] - m2.tab[0][2],
	     tab[1][0] - m2.tab[1][0], 
	     tab[1][1] - m2.tab[1][1], 
	     tab[1][2] - m2.tab[1][2],
	     tab[2][0] - m2.tab[2][0], 
	     tab[2][1] - m2.tab[2][1], 
	     tab[2][2] - m2.tab[2][2]);

  return res;
}




/*
**
**
**
**    Matrice 4x4
**
**
**
**
*/


//--- constructeurs ---
Matrix4x4::Matrix4x4() : Streamable()
{
  this->tab[0][0] = 0;
  this->tab[0][1] = 0;
  this->tab[0][2] = 0;
  this->tab[0][3] = 0;
  
  this->tab[1][0] = 0;
  this->tab[1][1] = 0;
  this->tab[1][2] = 0;
  this->tab[1][3] = 0;
  
  this->tab[2][0] = 0;
  this->tab[2][1] = 0;
  this->tab[2][2] = 0;
  this->tab[2][3] = 0;

  this->tab[3][0] = 0;
  this->tab[3][1] = 0;
  this->tab[3][2] = 0;
  this->tab[3][3] = 0;
}

Matrix4x4::Matrix4x4(double m00, double m01, double m02, double m03,
		     double m10, double m11, double m12, double m13,
		     double m20, double m21, double m22, double m23,
		     double m30, double m31, double m32, double m33) : Streamable()
{
  this->tab[0][0] = m00;
  this->tab[0][1] = m01;
  this->tab[0][2] = m02;
  this->tab[0][3] = m03;
  
  this->tab[1][0] = m10;
  this->tab[1][1] = m11;
  this->tab[1][2] = m12;
  this->tab[1][3] = m13;
  
  this->tab[2][0] = m20;
  this->tab[2][1] = m21;
  this->tab[2][2] = m22;
  this->tab[2][3] = m23;

  this->tab[3][0] = m30;
  this->tab[3][1] = m31;
  this->tab[3][2] = m32;
  this->tab[3][3] = m33;
}

Matrix4x4::Matrix4x4(double mat[4][4]) : Streamable()
{
  this->tab[0][0] = mat[0][0];
  this->tab[0][1] = mat[0][1];
  this->tab[0][2] = mat[0][2];
  this->tab[0][3] = mat[0][3];
  
  this->tab[1][0] = mat[1][0];
  this->tab[1][1] = mat[1][1];
  this->tab[1][2] = mat[1][2];
  this->tab[1][3] = mat[1][3];
  
  this->tab[2][0] = mat[2][0];
  this->tab[2][1] = mat[2][1];
  this->tab[2][2] = mat[2][2];
  this->tab[2][3] = mat[2][3];

  this->tab[3][0] = mat[3][0];
  this->tab[3][1] = mat[3][1];
  this->tab[3][2] = mat[3][2];
  this->tab[3][3] = mat[3][3];
}

//--- operations ---
Matrix4x4 Matrix4x4::transpose (void) const
{
  Matrix4x4 res (tab[0][0], tab[1][0], tab[2][0], tab[3][0],
	      tab[0][1], tab[1][1], tab[2][1], tab[3][1],
	      tab[0][2], tab[1][2], tab[2][2], tab[3][2],
	      tab[0][3], tab[1][3], tab[2][3], tab[3][3]);

  return res;
}

//--- methodes ---
void Matrix4x4::print(ostream& os) const
{
  for (int i = 0; i < 4; ++i)
    {
      for (int j = 0; j < 4; ++j)
	os << tab[i][j] << " ";
      os << endl;
    }
}

void Matrix4x4::read(istream& is)
{
  is >> this->tab[0][0];
}


Matrix4x4 Matrix4x4::operator/ (double div) const
{
  Matrix4x4 res (tab[0][0] / div, tab[0][1] / div, 
	      tab[0][2] / div, tab[0][3] / div,
	      tab[1][0] / div, tab[1][1] / div, 
	      tab[1][2] / div, tab[1][3] / div,
	      tab[2][0] / div, tab[2][1] / div, 
	      tab[2][2] / div, tab[2][3] / div,
	      tab[3][0] / div, tab[3][1] / div, 
	      tab[3][2] / div, tab[3][3] / div);
  
  return res;
}

Matrix4x4 Matrix4x4::operator+ (const Matrix4x4& m2) const
{
  Matrix4x4 res(tab[0][0] + m2.tab[0][0], 
	     tab[0][1] + m2.tab[0][1], 
	     tab[0][2] + m2.tab[0][2],
	     tab[0][2] + m2.tab[0][3],
	     tab[1][0] + m2.tab[1][0], 
	     tab[1][1] + m2.tab[1][1], 
	     tab[1][2] + m2.tab[1][2],
	     tab[1][2] + m2.tab[1][3],
	     tab[2][0] + m2.tab[2][0], 
	     tab[2][1] + m2.tab[2][1], 
	     tab[2][2] + m2.tab[2][2],
	     tab[2][2] + m2.tab[2][3],
	     tab[3][0] + m2.tab[3][0], 
	     tab[3][1] + m2.tab[3][1], 
	     tab[3][2] + m2.tab[3][2],
	     tab[3][2] + m2.tab[3][3]);

  return res;
}

Matrix4x4 Matrix4x4::operator- (const Matrix4x4& m2) const
{
  Matrix4x4 res(tab[0][0] - m2.tab[0][0], 
	     tab[0][1] - m2.tab[0][1], 
	     tab[0][2] - m2.tab[0][2],
	     tab[0][2] - m2.tab[0][3],
	     tab[1][0] - m2.tab[1][0], 
	     tab[1][1] - m2.tab[1][1], 
	     tab[1][2] - m2.tab[1][2],
	     tab[1][2] - m2.tab[1][3],
	     tab[2][0] - m2.tab[2][0], 
	     tab[2][1] - m2.tab[2][1], 
	     tab[2][2] - m2.tab[2][2],
	     tab[2][2] - m2.tab[2][3],
	     tab[3][0] - m2.tab[3][0], 
	     tab[3][1] - m2.tab[3][1], 
	     tab[3][2] - m2.tab[3][2],
	     tab[3][2] - m2.tab[3][3]);

  return res;
}

/*
** Cut here
*/

double	Matrix4x4::norme(double vect[4])
{
  unsigned int i;
  double s;
  
  s = 0.0;
  for (i = 0; i < 4; i++)
    s += (vect[i] * vect[i]);
  return sqrt(s);
}


vector<double> Matrix4x4::CalculVecteur()
{
  unsigned int i, j, k;
  double u[4], up[4];
  double n, t;

  /* fill vector with randomized values */
  for (i = 0; i < 4; i++)
    up[i] = -1 + i;
  k = 1;
  do
    {
      u = up;
      for (i = 0; i < 4; i++)
	{
	  t = 0;
	  for (j = 0; j < 4; j++)
	    t += this->get(i, j) * u[j];
	  up[i] = t;
	}
      n = this->norme (up);
      if (up[0] < 0)
	n = -n;
      t = 0;
      for (i = 0; i < 4; i++)
	{
	  up[i] = up[i] / n;
	  t += fabs(up[i] - u[i]);
	}
      k++;
    }
  while (k < 10000);
  vector<double> vec;
  for (i = 0; i < 4; i++)
    vec.push_back(up[i]);
  return (vec);
}

