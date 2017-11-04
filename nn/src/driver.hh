#ifndef _DRIVER_
#define _DRIVER_

#include <iostream>
#include <fstream>
#include <string>
#include "input.hh"
#include "driver.hh"

//FIXME: utilisation d'une grammaire
template<class InputType, class OutputType>
class Driver
{
public:
  Driver(const std::string& filename) : _filename(filename)
  {
    datafile = new std::ifstream(filename.c_str());
  }

  virtual ~Driver() { datafile->close(); } 

  virtual OutputType get_learnline(vector<Input<InputType> *>& inputs) = 0;
  virtual void getline(std::vector<Input<InputType> *>& inputs) = 0;
  virtual char *readline()
  {
    static char	line[255];
    datafile->getline(line, 255);
    return line;
  }

  void rearm()
  {
    datafile->close();
    datafile = new std::ifstream(_filename.c_str());    
  }

protected:
  std::ifstream	*datafile;
  std::string	_filename;
};

#endif /* _DRIVER_ */
