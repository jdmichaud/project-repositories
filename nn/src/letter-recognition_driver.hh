#ifndef _LETTER_RECOGNITION_
#define _LETTER_RECOGNITION_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "input.hh"
#include "driver.hh"

template<class InputType, class OutputType>
class Letter_recognition : public Driver<InputType, OutputType>
{
public:
  Letter_recognition(const std::string& filename) : 
    Driver<InputType, OutputType> (filename) {}

  //FIXME: grammaire
  OutputType get_learnline(vector<Input<InputType> *>& inputs)
  {
    char c;
    char comma;;
    double input;

    (*datafile) >> c;
    //std::cout << "input: ";
    for (unsigned i = 0; i < 16; ++i)
      {
	(*datafile) >> comma;
	(*datafile) >> input;
	//std::cout << input << " ";
	inputs[i]->setelt(input);
      }
    
    //    std::cout << std::endl;
    return c;
  }

  void getline(std::vector<Input<InputType> *>& inputs) 
  {
    double input;
    char comma;

    for (unsigned i = 0; i < 16; ++i)
      {
	(*datafile) >> input;
	inputs[i]->setelt(input);
	(*datafile) >> comma;
      }
  }

};

#endif /* _LETTER_RECOGNITION_ */
