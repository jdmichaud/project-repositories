#ifndef _BACKPROP_
#define _BACKPROP_

#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include "learn_algorithm.hh"

template<class InputType, class OutputType>
class Backprop : public LearnAlgo<InputType, OutputType>
{
public:
  Backprop(const std::string& filename,
	   Driver<InputType, OutputType> *driver,
	   NN<InputType> *nn, unsigned nlearnline, double min_error,
	   double epsilon) : 
    LearnAlgo<InputType, OutputType>(filename, driver, 
				     nn, nlearnline, min_error), 
    _epsilon(epsilon)
  {
    std::cout << "Learning algorithm: Back propagation" << std::endl;
  }

  virtual void learn()
  {
    _beginning = time(NULL);
    std::cout << "Learning sequence started at " 
	      << localtime(&_beginning)->tm_hour << "h"
	      << localtime(&_beginning)->tm_min << "m"
	      << localtime(&_beginning)->tm_sec << "s"
	      << std::endl;
    
    time_t best_time = 0;
    OutputType desired;
    unsigned count = 0;
    std::vector<double>	errors;
    std::vector<bool>	good;
    double mean_error = 0.0;
    double best_percentage = 0.0;

    do {
      desired = _driver->get_learnline(_nn->get_inputs());
      _nn->activate();
      backpropagation(desired);
      _nn->update_weights();

      mean_error = 0.0;
      errors.push_back(compute_error(desired));
      if (errors.size() > 1000)
	errors.erase(errors.begin());
      for (unsigned i = 0; i < errors.size(); ++i)
	mean_error += errors[i];
      mean_error /= errors.size();

      if (_correspondence[desired] == _nn->get_answer())
	good.push_back(true);
      else
	good.push_back(false);
      if (good.size() > 1000)
	good.erase(good.begin());
      
      if ((count % 1000) == 0)
	{
	  /*std::cout << "desired: " << desired << " (" 
		    << _correspondence[desired]
		    << " obtained: " << _nn->get_answer() << ")" << std::endl;
		    _nn->print_output();*/
	  std::cout << "mean error: ";
	  std::cout << mean_error << std::endl;    

	  unsigned ngood = std::count(good.begin(), good.end(), true);
	  unsigned ntot = good.size();
	  double percentage = (float) ngood / ((float) ntot) * 100;
	  if ((ntot > 100) && best_percentage < percentage)
	    {
	      best_time = time(NULL);
	      best_percentage = percentage;
	    }
	  if (percentage > 96)
	    break;
	    
	  std::cout << "good: " << ngood << " total: " << ntot 
		    << " (" << percentage
		    << "%, best: " << best_percentage << "% at "
		    << best_time - _beginning << " s, no move since: " 
		    << time(NULL) - best_time << " s)" << std::endl;

	}
      ++count;
      if (!(count % _nlearnline))
	{
	  _driver->rearm();
	  std::cout << "driver rearmed" << std::endl;
	}

    } while (mean_error > _min_error);
    
    std::cout << count << " iterations in " << time(NULL) - _beginning
	      << std::endl;
  }

  /*
  ** L : couche
  ** j : neurone
  */
  double dEdyj(unsigned L, unsigned j, OutputType desired)
  {
    double zj = _nn->get_neuron(L, j)->getOutput();

    if (L == _nn->get_nlayers() - 1)
      return zj * (1 - zj) * (zj - (j == _correspondence[desired]));
    else
      {
	double sum = 0.0;
	for (unsigned k = 0; k < _nn->get_nneurons(L + 1); ++k)
	  sum += _nn->get_neuron(L + 1, k)->_weights[j] *
	    dEdyj(L + 1, k, desired);
	return zj * (1 - zj) * sum;
      }
  }

  void backpropagation(OutputType desired)
  {
    for (unsigned L = _nn->get_nlayers() - 1; L != 0; --L)
      for (unsigned j = 0; j < _nn->get_nneurons(L); ++j)
	for (unsigned i = 0; i < _nn->get_nneurons(L - 1); ++i)
	  {
	    double delta = - _epsilon * 
	      (_nn->get_neuron(L - 1, i)->getOutput() * dEdyj(L, j, desired));

	    _nn->get_neuron(L, j)->_adjusted_weights[i] = 
	      _nn->get_neuron(L, j)->_weights[i] + delta;
	  }
  }

private:
  double	_epsilon;
};

#endif /* _BACKPROP_ */
