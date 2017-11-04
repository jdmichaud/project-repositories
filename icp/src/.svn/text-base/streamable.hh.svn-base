//
// streamable.hh for  in 
// 
// Made by GIZMO
// Login   <grimau_r@epita.fr>
// 
// Started on  Mon Feb  4 15:23:15 2002 GIZMO
// Last update Sun May 19 12:15:11 2002 GIZMO
//

#ifndef STREAMABLE_HH
# define STREAMABLE_HH

using namespace std;

#include <iostream>

class Streamable
{
public:
  Streamable() {}
  virtual void print(ostream& os) const = 0;
  virtual void read(istream& is) = 0;
  
  friend ostream& operator<< (ostream& os, Streamable& stream)
  {
    stream.print(os);
    return (os);
  }
  
  friend istream& operator>> (istream& is, Streamable& stream)
  {
    stream.read(is);
    return (is);
  }
  
};

#endif // ndef STREAMABLE_HH
