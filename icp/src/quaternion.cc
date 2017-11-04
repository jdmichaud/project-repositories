//
// quaternion.cc for  in 
// 
// Made by GIZMO
// Login   <grimau_r@epita.fr>
// 
// Started on  Mon Feb  4 09:59:19 2002 GIZMO
// Last update Sun May 26 15:33:55 2002 jean-daniel michaud
//

#include <iostream>
#include <math.h>
#include <assert.h>

#include "streamable.hh"
#include "quaternion.hh"

//--- constructeurs ---
Quaternion::Quaternion() : Streamable()
{
  this->w = 0;
  
  this->x = 0;
  this->y = 0;
  this->z = 0;
}

Quaternion::Quaternion(const Quaternion& quat) : Streamable()
{
  this->w = quat.w;
  
  this->x = quat.x;
  this->y = quat.y;
  this->z = quat.z;
}

Quaternion::Quaternion(float x, float y, float z, float w) : Streamable()
{
  this->w = w;
  
  this->x = x;
  this->y = y;
  this->z = z;
}

//--- operations ---
Quaternion Quaternion::operator+ (const Quaternion& quat) const
{
  Quaternion q;
  
  q.w = this->w + quat.w;
  q.x = this->x + quat.x;
  q.y = this->y + quat.y;
  q.z = this->z + quat.z;
  
  return q;
}

Quaternion Quaternion::operator- (const Quaternion& quat) const
{
  Quaternion q;
  
  q.w = this->w - quat.x;
  q.x = this->x - quat.x;
  q.y = this->y - quat.y;
  q.z = this->z - quat.z;
  
  return q;
}

Quaternion Quaternion::operator* (float a) const
{
  Quaternion q;
  
  q.w = this->w * a;
  q.x = this->x * a;
  q.y = this->y * a;
  q.z = this->z * a;
  
  return q;
}

Quaternion operator* (float a, Quaternion& quat)
{
  return (quat * a);
}

Quaternion Quaternion::operator* (const Quaternion& quat) const
{
  Quaternion q;
  
  q.w = this->w * quat.w - this->x * quat.x -
    this->y * quat.y - this->z * quat.z;;
  q.x = this->w * quat.x + this->y * quat.w +
    this->y * quat.z - this->z * quat.y;
  q.y = this->w * quat.y - this->x * quat.z +
    this->y * quat.w + this->z * quat.x;
  q.z = this->w * quat.z + this->x * quat.y -
    this->y * quat.x + this->z * quat.w;
  
  return q;
}

Quaternion Quaternion::operator~ (void)
{
  this->w = this->w;
  this->x = -this->x;
  this->y = -this->y;
  this->z = -this->z;
  
  return *this;
}

Quaternion Quaternion::operator/ (const Quaternion& quat) const
{
  return (this->inverse() * quat);
}


//--- operations et affectations ---
void Quaternion::operator+= (const Quaternion& quat)
{
  this->w += quat.w;
  this->x += quat.x;
  this->y += quat.y;
  this->z += quat.z;
}

void Quaternion::operator-= (const Quaternion& quat)
{
  this->w = this->w - quat.x;
  this->x = this->x - quat.x;
  this->y = this->y - quat.y;
  this->z = this->z - quat.z;
}

void Quaternion::operator*= (float a)
{
  this->w = this->w * a;
  this->x = this->x * a;
  this->y = this->y * a;
  this->z = this->z * a;
}

void Quaternion::operator*= (const Quaternion& quat)
{
  this->w = this->w * quat.w - this->x * quat.x -
    this->y * quat.y - this->z * quat.z;;
  this->x = this->w * quat.x + this->y * quat.w +
    this->y * quat.z - this->z * quat.y;
  this->y = this->w * quat.y - this->x * quat.z +
    this->y * quat.w + this->z * quat.x;
  this->z = this->w * quat.z + this->x * quat.y -
    this->y * quat.x + this->z * quat.w;
}


//--- methodes ---
float Quaternion::norme(void) const
{
  return (sqrt(this->w * this->w + this->x * this->x +
	       this->y * this->y + this->z * this->z));
}

Quaternion Quaternion::normalize(void) const
{
  Quaternion q;
  
  q = this->operator* (1 / this->norme());
  return q;
}

Quaternion Quaternion::conjugue(void) const
{
  Quaternion q;
  
  q.w = this->w;
  q.x = -this->x;
  q.y = -this->y;
  q.z = -this->z;
  
  return q;
}

Quaternion Quaternion::inverse(void) const
{
  float	tmp;
  
  assert(this->norme() != 0);
  tmp = this->w * this->w + this->x * this->x +
    this->y * this->y + this->z * this->z;
  assert(tmp != 0);
  tmp = 1 / tmp;
  return (*this * tmp);
}

float Quaternion::scalar(const Quaternion& quat) const
{
  return (this->w * quat.w + this->x * quat.x +
	  this->y * quat.y + this->z * quat.z);
}

void Quaternion::print(ostream& os) const
{
  os << this->x << " "
     << this->y << " "
     << this->z << " "
     << this->w;
}

void Quaternion::read(istream& is)
{
  is >> this->x >> this->y >> this->z >> this->w;
}
