//
// parse.hh for  in 
// 
// Made by GIZMO
// Login   <grimau_r@epita.fr>
// 
// Started on  Sun May 19 11:05:23 2002 GIZMO
// Last update Sun May 19 13:46:43 2002 jean-daniel michaud
//

#include <string>
#include <vector>
#include <iostream>
#include <vector.hh>
#include "model.hh"

extern "C"
{
#include "pgm.h"
}

using namespace std;


class Parse
{
public:
  Parse() {}
  Parse(const string point_file, const string pgm_file) :
    _point_filename(point_file),
    _pgm_filename(pgm_file) {}
  
  void setPointFilename(const string filename)
  {
    _point_filename = filename;
  }
  void setPGMFilename(const string filename)
  {
    _pgm_filename = filename;
  }

  string getPointFilename(void) const
  {
    return _point_filename;
  }

  string getPGMFilename(void) const
  {
    return _pgm_filename;
  }
  
  std::vector<Vector3D>		parse_point(void) const;
  Model&			generate_points(void) const;
  gray				**parse_pgm(int *cols, 
					    int *rows, 
					    gray *maxval) const;
  
  
private:
  string	_point_filename;
  string	_pgm_filename;
  
};
