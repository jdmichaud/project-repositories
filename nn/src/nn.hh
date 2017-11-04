#ifndef _NN_
#define _NN_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "input.hh"
#include "neuron.hh"
#include "input_neuron.hh"

template<class InputType>
class NN
{
public:
  NN() {}

  NN(unsigned nlayers, vector<unsigned> nneurons, 
     tf_activation *functions, double bias) : _nlayers(nlayers), 
					      _nneurons(nneurons)
  {
    std::cout << "network creation ... ";
    for (unsigned i = 0; i < nlayers; ++i)
      {
	_network.push_back(std::vector<Neuron *>());
	std::cout << nneurons[i] << " ";
	for (unsigned j = 0; j < nneurons[i]; ++j)
	  {
	    if (i == 0)
	      {
		Input<InputType>	*input = new Input<InputType>();
		_inputs.push_back(input);
		_network[i].push_back(new Input_neuron<InputType>
				      (functions[i], bias, input));
	      }
	    else
	      _network[i].push_back(new Neuron(functions[i], bias, 
					       _network[i - 1]));
	  }
      }
    std::cout << std::endl;
  }

  void activate()
  {
    //std::cout << "network activation: ";
    for (unsigned i = 0; i < _nlayers; ++i)
      for (unsigned j = 0; j < _nneurons[i]; ++j)
	_network[i][j]->activate();
  }

  void activate(std::vector<double> weights)
  {
    apply_weights(weights);

    for (unsigned i = 0; i < _nlayers; ++i)
      for (unsigned j = 0; j < _nneurons[i]; ++j)
	_network[i][j]->activate();
  }

  void apply_weights(std::vector<double> weights)
  {
    unsigned count = 0;

    for (unsigned L = 1; L < _nlayers - 1; ++L)
      for (unsigned i = 0; i < _nneurons[L]; ++i)
	for (unsigned j = 0; j < _nneurons[L - 1]; ++j, ++count)
	  _network[L][i]->_weights[j] = weights[count];
  }

  std::vector<Input<InputType> *>& get_inputs()
  {
    return _inputs;
  }

  void update_weights()
  {
    for (unsigned i = 0; i < _nlayers; ++i)
      for (unsigned j = 0; j < _nneurons[i]; ++j)
	_network[i][j]->update_weights();    
  }

  void adjust_weights(double learning_rate = 1.0)
  {
    for (unsigned i = 0; i < _nlayers; ++i)
      for (unsigned j = 0; j < _nneurons[i]; ++j)
	_network[i][j]->adjust_weights(learning_rate);    
  }


  inline unsigned get_nneurons(unsigned i) { return _nneurons[i]; }
  inline unsigned get_nlayers() { return _nlayers; }
  inline double get_output(unsigned i) 
  { return _network[_nlayers - 1][i]->getOutput(); }
  inline Neuron *get_neuron(unsigned i, unsigned j) { return _network[i][j]; } 

  void print_output()
  {
    for (unsigned i = 0; i < _nneurons[_nlayers - 1]; ++i)
      std::cout << _network[_nlayers - 1][i]->getOutput() << " ";
    std::cout << std::endl;
  }

  void write(const std::string& filename)
  {
    std::ofstream os(filename.c_str());

    os << _nlayers << std::endl; 
    for (unsigned L = 0; L < _nlayers; ++L)
      os << _nneurons[L] << " ";
    os << _network[0][0]->get_bias();
    os << std::endl;

    for (unsigned L = _nlayers - 1; L != 0; --L)
      for (int j = _nneurons[L] - 1; j >= 0; --j)
	{
	  for (int i = _nneurons[L - 1] - 1; i >= 0; --i)
	    os << _network[L][j]->_weights[i] << " ";
	  os << endl;
	}
  }

  void read(const std::string& filename)
  {
    std::ifstream os(filename.c_str());

    os >> _nlayers;
    for (unsigned L = 0; L < _nlayers; ++L)
      {
	unsigned n;
	os >> n;
	_nneurons.push_back(n);
      }
    double bias;
    os >> bias;

    std::cout << "network creation ... ";
    for (unsigned i = 0; i < _nlayers; ++i)
      {
	_network.push_back(std::vector<Neuron *>());
	std::cout << _nneurons[i] << " ";
	for (unsigned j = 0; j < _nneurons[i]; ++j)
	  {
	    if (i == 0)
	      {
		Input<InputType>	*input = new Input<InputType>();
		_inputs.push_back(input);
		_network[i].push_back(new Input_neuron<InputType>
				      (NULL, bias, input));
	      }
	    else
	      _network[i].push_back(new Neuron(NULL, bias, 
					       _network[i - 1]));
	  }
      }

    for (unsigned L = _nlayers - 1; L != 0; --L)
      for (int j = _nneurons[L] - 1; j >= 0; --j)
	for (int i = _nneurons[L - 1] - 1; i >= 0; --i)
	  os >> _network[L][j]->_weights[i];
  }

  unsigned get_answer()
  {
    double max = 0.0;
    unsigned max_output = 0;
    for (unsigned i = 0; i < _nneurons[_nlayers - 1]; ++i)
      if (max < _network[_nlayers - 1][i]->getOutput())
	{
	  max = _network[_nlayers - 1][i]->getOutput();
	  max_output = i;
	}

    return max_output; 
  }
  
private:
  std::vector<std::vector<Neuron *> >	_network;
  std::vector<Input<InputType> *>	_inputs;
  unsigned				_nlayers;
  std::vector<unsigned>			_nneurons;
};

#endif /* _NN_ */
