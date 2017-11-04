#ifndef _INPUT_
#define _INPUT_

#include <string>
#include "neuron.hh"

template<class T = double>
class Input
{
public:
  Input() 
  {
    elt = new T;
  }
  
  //FIXME
  double getDouble()
  {
    /*std::string *s;
    if (s = dynamic_cast<std::string *> (elt))
    return atof(s->c_str());*/

    return (double) (*elt);
  }

  void setelt(T& value)
  {
    (*elt) = value;
  }

private:
  T	*elt;
};

#endif /* _INPUT_ */
