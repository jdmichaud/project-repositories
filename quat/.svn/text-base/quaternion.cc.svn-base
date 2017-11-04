//
// quaternion.cc for quaternion in 
// 
// Made by Jean-Daniel Michaud
// Login   <JeDi@epita.fr>
// 
// Started on  Fri Feb  1 15:17:45 2002 Jean-Daniel Michaud
// Last update Thu Feb 14 18:11:44 2002 jean-daniel michaud
//

#include <math.h>
#include <assert.h>
#include "quaternion.hh"

//
// Operateurs pour Streamable
//

ostream&	operator<<(ostream& out, const Streamable& stream)
{
  stream.print(out);
  return (out);
}

istream&	operator>>(istream& in, Streamable& stream)
{
  stream.read(in);
  return (in);
}

//
// Constructeurs de Quaternions
//

// Constructeur par defaut
//  Initialise les attributs a zero

Quaternion::Quaternion()
{
  _w = 0;
  _x = 0;
  _y = 0;
  _z = 0;
}

// Constructeur par copie

Quaternion::Quaternion(const Quaternion& q)
{
  _w = q.getW();
  _x = q.getX();
  _y = q.getY();
  _z = q.getZ();
}

// Constructeur par valeur

Quaternion::Quaternion(float w, float x, float y, float z)
{
  _w = w;
  _x = x;
  _y = y;
  _z = z;
}

//
// Operateurs
//

// Addition

Quaternion	Quaternion::operator+(const Quaternion &q) const
{
  return (Quaternion(_w + q.getW(), _x + q.getX(), 
		     _y + q.getY(), _z + q.getZ()));
}

// Soustraction

Quaternion	Quaternion::operator-(const Quaternion &q) const
{
  return (Quaternion(_w - q.getW(), _x - q.getX(), 
		     _y - q.getY(), _z - q.getZ()));
}

// Multiplication par un quaternion

Quaternion	Quaternion::operator*(const Quaternion &q) const
{
  return (Quaternion(_w * getW() - _x * getX() - _y * getY() - _z * getZ(),
		     _w * getX() + _y * getW() + _z * getZ() + _z * getY(),
		     _w * getY() - _x * getZ() + _y * getW() + _z * getX(),
		     _w * getZ() + _x * getY() - _y * getX() + _z * getW()));
}

// Multiplication par un reel

Quaternion	Quaternion::operator*(const float f) const
{
  return (Quaternion(_w * f, _x * f, _y * f, _z * f));
}

// Division

Quaternion	Quaternion::operator/(const Quaternion &q) const
{
  return (*this * q.inverse());
}

// Division par un reel

Quaternion	Quaternion::operator/(const float f) const
{
  return (Quaternion(_w / f, _x / f, _y / f, _z / f));
}

// Affectation

Quaternion&	Quaternion::operator=(const Quaternion &q)
{
  _w = q.getW();
  _x = q.getX();
  _y = q.getY();
  _z = q.getZ();
  return (*this);
}

// Operateur de conjuguaison

Quaternion&	Quaternion::operator~()
{
  _x -= _x;
  _y -= _y;
  _z -= _z;
  return (*this);
}

//
// Operateur d'affectation
//

// Addition

Quaternion&	Quaternion::operator+=(const Quaternion &q)
{
  _w += q.getW(); 
  _x += q.getX(); 
  _y += q.getY(); 
  _z += q.getZ();
  return (*this);
}

// Division

Quaternion&	Quaternion::operator-=(const Quaternion &q)
{
  _w -= getW(); 
  _x -= getX(); 
  _y -= getY(); 
  _z -= getZ();
  return (*this);
}

// Multiplication par un quaternion

Quaternion&	Quaternion::operator*=(const Quaternion &q)
{
  _w = _w * getW() - _x * getX() - _y * getY() - _z * getZ();
  _x = _w * getX() + _y * getW() + _z * getZ() + _z * getY();
  _y = _w * getY() - _x * getZ() + _y * getW() + _z * getX();
  _z = _w * getZ() + _x * getY() - _y * getX() + _z * getW();
  return (*this);
}

// Multiplication par un reel

Quaternion&	Quaternion::operator*=(const float f)
{
  _w *= f;
  _x *= f;
  _y *= f;
  _z *= f;
  return (*this);
}

// Division

Quaternion&	Quaternion::operator/=(const Quaternion &q) 
{
  *this *= q.inverse();
  return (*this);
}

// Division par un reel

Quaternion&	Quaternion::operator/=(const float f) 
{
  _w /= f;
  _x /= f;
  _y /= f;
  _z /= f;
  return (*this);
}

//
// Methodes
//

// Conjuguaison

Quaternion	Quaternion::conjugue() const
{
  return (Quaternion(_w, -_x, -_y, -_z));
}

// Inverse

Quaternion	Quaternion::inverse() const
{
  Quaternion	*q = new Quaternion;

  *q = conjugue();
  assert((q->norme() * q->norme()));
  *q *= 1 / (q->norme() * q->norme());
  return (*q);
}

// Norme

float		Quaternion::norme() const
{
  return (sqrt((_w * _w) + (_x * _x) + (_y * _y) + (_z * _z)));
}

// Normalisation

void		Quaternion::normalize()
{
  *this = *this /= norme();
}

//
// Methode d'encapsulation
//

float		Quaternion::getW() const
{
  return (_w);
}

float		Quaternion::getX() const
{
  return (_x);
}

float		Quaternion::getY() const
{
  return (_y);
}

float		Quaternion::getZ() const
{
  return (_z);
}

// Methode d'E/S

void		Quaternion::print(ostream& out) const
{
  out << _w << " " << _x << " " << _y << " " << _z << endl;
}

void		Quaternion::read(istream& in)
{
  in >> _x >> _y >> _z >> _w;
}
