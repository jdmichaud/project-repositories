#ifndef _NEURON_
#define _NEURON_

#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>

typedef double	(*tf_activation)(double);

class Neuron
{
public:
  Neuron(tf_activation function, double bias, 
	 std::vector<Neuron *>& previous_layer) : 
    _inputs(previous_layer),
    _activation_function(function), 
    _bias(bias)
  {
    init_weights();
  }

  Neuron(tf_activation function, double bias) :
    _activation_function(function), 
    _bias(bias)
  {
    init_weights();
  }

  virtual ~Neuron() {}
 
  void init_weights()
  {
    //    srand((unsigned) time(NULL));
    srand((unsigned) this);
    for (unsigned i = 0; i < _inputs.size(); ++i)
      {
	double toto = rand() % 10000;
	toto = toto / 5000.0;
	//std::cout << "toto: " << toto  - 1.0<< std::endl;
	_weights.push_back(toto - 1.0);
	_adjusted_weights.push_back(0.0);
      }
  }

  //Fixme
  virtual double activate()
  {
    double sum = 0.0;
    for (unsigned i = 0; i < _inputs.size(); ++i)
      sum += _weights[i] * _inputs[i]->getOutput();
    
    if (_activation_function)
      {
	_output = _activation_function(sum - _bias);
	return _output;
      }
    else
      {
	_output = sigmoide(sum - _bias);
	return _output;
      }

    return 0.0;
  }

  void	update_weights()
  {
    copy(_adjusted_weights.begin(), _adjusted_weights.end(), _weights.begin());
  }

  void	adjust_weights(double learning_rate = 0.0)
  {
    for (unsigned i = 0; i < _weights.size(); ++i)
      {
	_weights[i] += learning_rate * _adjusted_weights[i];
	_adjusted_weights[i] = 0.0;
      }
  }

  inline double getOutput() { return _output; }
  inline double get_bias() { return _bias; }
  inline double sigmoide(double x) { return (1.0 / (1.0 + exp(- 0.05 * x))); }
public:
  std::vector<double>		_weights;
  std::vector<double>		_adjusted_weights;
private:
  std::vector<Neuron *>		_inputs;

protected:
  tf_activation			_activation_function;
  double			_bias;
  double			_output;

};

#endif /* _NEURON */
