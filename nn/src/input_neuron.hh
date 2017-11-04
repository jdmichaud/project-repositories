#ifndef _INPUT_NEURON_
#define _INPUT_NEURON_

#include <vector>
#include "neuron.hh"
#include "input.hh"

template<class T = double>
class Input_neuron : public Neuron
{
public:
  Input_neuron(tf_activation function, double threshold, Input<T> *input) :
    Neuron(function, threshold), _input(input)
  {}

  virtual double activate()
  {
    if (_activation_function)
      _output = _activation_function(_input->getDouble());
    else
      _output = _input->getDouble();

    return _output;
  }

protected:
  Input<T>		*_input;

};

#endif /* _INPUT_NEURON_ */
