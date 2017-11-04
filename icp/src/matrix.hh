//
// matrix.hh for  in 
// 
// Made by GIZMO
// Login   <grimau_r@epita.fr>
// 
// Started on  Mon Feb  4 15:48:58 2002 GIZMO
// Last update Mon May 27 18:03:57 2002 jean-daniel michaud
//

#ifndef MATRIX_HH
# define MATRIX_HH

#include <iostream>

#include "streamable.hh"
#include "quaternion.hh"
#include "vector.hh"

class Matrix : public Streamable
{
public:
  Matrix();
  Matrix(double m00, double m01, double m02,
	 double m10, double m11, double m12,
	 double m20, double m21, double m22);
  
  Vector3D& operator* (const Vector3D& vect) const;
  Matrix operator/ (double div) const;
  Matrix operator* (double div) const;
  Matrix operator+ (const Matrix& m2) const;
  Matrix operator- (const Matrix& m2) const;
  Matrix transpose (void) const;
  double get(int i, int j) { return tab[i][j]; }

  double	trace(void) const
  {
    double	res = 0;

    for (unsigned i = 0; i < 3; ++i)
      res += tab[i][i];
    return res;
  }

  virtual void print(ostream& os) const;
  virtual void read(istream& is);
private:
  double tab[3][3];
};

Matrix quat2mat(const Quaternion& quat);
Matrix operator* (const Vector3D v1, const Vector3D v2);


class Matrix4x4 : public Streamable
{
public:
  Matrix4x4();
  Matrix4x4::Matrix4x4(double mat[4][4]);
  Matrix4x4::Matrix4x4(double m00, double m01, double m02, double m03,
		       double m10, double m11, double m12, double m13,
		       double m20, double m21, double m22, double m23,
		       double m30, double m31, double m32, double m33);
  
  Matrix4x4 operator/ (double div) const;
  Matrix4x4 operator+ (const Matrix4x4& m2) const;
  Matrix4x4 operator- (const Matrix4x4& m2) const;
  Matrix4x4 transpose (void) const;
  void	_set(int i, int j, double val) { tab[i][j] = val; }
  double get(int i, int j) { return tab[i][j]; }

  double	trace(void) const
  {
    double	res = 0;

    for (unsigned i = 0; i < 3; ++i)
      res += tab[i][i];
    return res;
  }

  /*
  ** Vecteurs propres ...
  */
public:
  vector<double> CalculVecteur();

private:
  double norme(double vect[4]);


public:
  virtual void print(ostream& os) const;
  virtual void read(istream& is);

private:
  double tab[4][4];
};

#endif // ndef MATRIX_HH

