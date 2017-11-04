//
// var.hh for minimake in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sat Feb 23 19:00:22 2002 jean-daniel michaud
// Last update Sun Feb 24 10:05:34 2002 jean-daniel michaud
//

#ifndef VAR_HH_
# define VAR_HH_

#include <iostream>

class Variable
{
public:
  Variable(void) {}
  Variable(const string& name, const string& value) : 
    _name(name), _value(value)
  {
  }
  ~Variable(void) {}

  string getName(void) const { return _name; }
  string getValue(void) const { return _value; }
  
private:
  string	_name;
  string	_value;
};

#endif /* !VAR_HH_ */
