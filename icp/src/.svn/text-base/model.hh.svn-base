//
// model.hh for math in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sun May 19 13:30:25 2002 jean-daniel michaud
// Last update Thu May 30 18:02:22 2002 jean-daniel michaud
//

#ifndef MODEL_HH_
# define MODEL_HH_

#include <vector>
#include <GL/glut.h>
#include "object.hh"
#include "opengl.hh"
#include "vector.hh"
#include "object.hh"

extern float	hscl; 
extern float	vscl;
extern float	pscl;
extern float	hdcl;
extern float	vdcl;
extern float	pdcl;

class Model : public Object
{
public:
  Model ()
  {}
  Model (unsigned cols, unsigned rows, unsigned maxval) : 
    _cols (cols), _rows(rows), _maxval(maxval)
  {}

  virtual ~Model () {}

  virtual void  calcBarycentre(void)
  {
    double x = 0.;
    double y = 0.;
    double z = 0.;
    
    for (unsigned int i = 0; i < _points.size(); ++i)
      {
	x += _points[i].getX();
	y += _points[i].getY();
	z += _points[i].getZ();
      }
    _bary.setX(x / double (_points.size()));
    _bary.setY(y / double (_points.size()));
    _bary.setZ(z / double (_points.size()));
    hdcl = _bary.getX () / hscl;
    vdcl = _bary.getY () / vscl;
    pdcl = _bary.getZ () / pscl;
    if (verbose_p)
      {
	cout << "calcul du barycentre du model" << endl;
	cout << _bary << endl;
      }
  }

private:
  unsigned _cols;
  unsigned _rows;
  unsigned _maxval;
};


#endif
