//
// quaternion.hh for quaternion in 
// 
// Made by Jean-Daniel Michaud
// Login   <JeDi@epita.fr>
// 
// Started on  Fri Feb  1 15:18:06 2002 Jean-Daniel Michaud
// Last update Thu Feb 14 13:25:23 2002 jean-daniel michaud
//

#ifndef QUATERNION_HH_
# define QUATERNION_HH_

#include <iostream>

using namespace std;

class Streamable
{
public:

  virtual void		print(ostream& out) const = 0;
  virtual void		read(istream& in) = 0;
};

class Quaternion : public Streamable
{
private:
  float	_w;
  float	_x;
  float	_y;
  float	_z;

public:
  Quaternion();
  Quaternion(const Quaternion& q);
  Quaternion(float w, float x, float y, float z);
  virtual ~Quaternion()
  {
  }
  
  Quaternion	operator+(const Quaternion& q) const;
  Quaternion	operator-(const Quaternion& q) const;
  Quaternion	operator*(const Quaternion& q) const;
  Quaternion	operator*(const float f) const;
  Quaternion	operator/(const Quaternion& q) const;
  Quaternion	operator/(const float f) const;
  Quaternion&	operator=(const Quaternion& q);
  Quaternion&	operator~();

  Quaternion&	operator+=(const Quaternion& q);
  Quaternion&	operator-=(const Quaternion& q);
  Quaternion&	operator*=(const Quaternion& q);
  Quaternion&	operator*=(const float f);
  Quaternion&	operator/=(const Quaternion& q);
  Quaternion&	operator/=(const float q);

  Quaternion	conjugue() const;
  Quaternion	inverse() const;
  float		norme() const;
  void		normalize();

  float		getW() const;
  float		getX() const;
  float		getY() const;
  float		getZ() const;

  void		print(ostream& out) const;
  void		read(istream& in);
};


ostream&	operator<<(ostream& out, const Streamable& stream);
istream&	operator>>(istream& in, Streamable& stream);

#endif // !QUATERNION_HH_
