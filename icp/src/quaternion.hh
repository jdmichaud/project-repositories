//
// quaternion.hh for  in 
// 
// Made by GIZMO
// Login   <grimau_r@epita.fr>
// 
// Started on  Mon Feb  4 09:59:27 2002 GIZMO
// Last update Fri Feb 15 00:02:27 2002 GIZMO
//

#ifndef QUATERNION_HH
# define QUATERNION_HH

# include <iostream>
# include "streamable.hh"

class Quaternion : public Streamable
{
public:
  // constructeurs
  Quaternion();
  Quaternion(const Quaternion& quat);
  Quaternion(float x, float y, float z, float w);
  
  // operations
  Quaternion operator+ (const Quaternion& quat) const;
  Quaternion operator- (const Quaternion& quat) const;
  Quaternion operator* (float a) const;
  Quaternion operator* (const Quaternion& quat) const;
  Quaternion operator/ (const Quaternion& quat) const;
  Quaternion operator~ (void);
  
  // operations et affectations
  void operator+= (const Quaternion& quat);
  void operator-= (const Quaternion& quat);
  void operator*= (float);
  void operator*= (const Quaternion& quat);
  void operator/= (const Quaternion& quat);
  
  Quaternion conjugue(void) const;
  float norme(void) const;
  Quaternion normalize(void) const;
  Quaternion inverse(void) const;
  float scalar(const Quaternion& quat) const;
  
  // accesseurs
  float getW() const { return w; };
  float getX() const { return x; };
  float getY() const { return y; };
  float getZ() const { return z; };
  
  // autres methodes
  virtual void print(ostream& os) const;
  virtual void read(istream& is);
  
private:
  // w pour la partie REEL
  float w;
  // x, y, z pour la partie IMG
  float x, y, z;
};


#endif // ndef QUATERNION_HH
