#ifndef _TESTNN_
#define _TESTNN__

#include <iostream>
#include "driver.hh"
#include "nn.hh"

template<class InputType, class OutputType>
class TestNN
{
public:
  TestNN(const std::string& filename, 
	 Driver<InputType, OutputType> *driver, NN<InputType> *nn, 
	 unsigned borneinf, unsigned bornesup) :  _driver(driver),_nn(nn)
  {
    _bornesup = bornesup;
    _borneinf = borneinf;
    if (borneinf > bornesup)
      {
	std::cerr << "warning: borneinf is inferior to bornesup, reordering"
		  << std::endl;

	_bornesup = borneinf;
	_borneinf = bornesup;
      }

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
	std::cout << " " << output << " - " << input << std::endl;
	_correspondence[output] = input;
      }

  }

  void test()
  {
    unsigned count = 0;
    _good = 0;
    _bad = 0;

    while (count < _borneinf)
      {
	_driver->readline();
	count++;
      }

    OutputType desired;
    OutputType obtained;
    while (count < _bornesup)
      {
	desired = _driver->get_learnline(_nn->get_inputs());
	_nn->activate();
	//error = compute_error(desired);
	obtained = _correspondence[_nn->get_answer()];
	std::cout << "desired: " << desired << " " 
		  << "obtained: " << obtained << std::endl;	  
	if (desired == obtained)
	  ++_good;
	else
	  ++_bad;
	count++;
      }

    std::cout << "good: " << _good << " bad: " << _bad 
	      << " (" << ((float) _good) / ((float) (_good + _bad)) * 100 
	      << "%)" << std::endl;
  }

private:
  std::ifstream *corrfile;
  std::map<unsigned, OutputType>	_correspondence;
  Driver<InputType, OutputType>	*_driver;
  NN<InputType>			*_nn;
  unsigned			_borneinf;
  unsigned			_bornesup;
  unsigned			_good;
  unsigned			_bad;

};

#endif /* _TESTNN_ */
