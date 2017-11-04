#ifndef _LEARNALGO_
#define _LEARNALGO_

#include <time.h>
#include <iostream> 
#include <fstream>
#include <string>
#include <map>
#include "nn.hh"
#include "input.hh"
#include "driver.hh"

template<class InputType, class OutputType>
class LearnAlgo
{
public:
  LearnAlgo(const std::string& filename, 
	    Driver<InputType, OutputType> *driver,
	    NN<InputType> *nn, unsigned nlearnline,
	    double min_error) : _driver(driver), _nn(nn), 
				 _nlearnline(nlearnline), 
				 _min_error(min_error)
  {
    corrfile = new std::ifstream(filename.c_str());
    OutputType input;
    int output;
    std::cout << "Correspondance: " << std::endl;
    while (!corrfile->eof())
      {
	(*corrfile) >> input;
	if (corrfile->eof())
	  break;
	(*corrfile) >> output;
	std::cout << " " << input << " - " << output << std::endl;
	_correspondence[input] = output;
      }
  }
  
  virtual ~LearnAlgo() { corrfile->close(); }

  virtual void learn() = 0;
  virtual double compute_error(OutputType desired)
  {
    double sum = 0;

    for (unsigned i = 0; i < _nn->get_nneurons(_nn->get_nlayers() - 1); ++i)
      sum += pow(_nn->get_output(i) - (i == _correspondence[desired]), 2);

    return 0.5 * sum;
  }

protected:
  std::ifstream *corrfile;
  std::map<OutputType, unsigned>	_correspondence;
  Driver<InputType, OutputType> *_driver;
  NN<InputType>			*_nn;
  unsigned			_nlearnline;
  double			_min_error;

  time_t			_beginning;
};

#endif /* _LEARNALGO_ */
