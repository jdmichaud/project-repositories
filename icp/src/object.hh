//
// object.hh for math in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Mon May 20 12:00:36 2002 jean-daniel michaud
//

#ifndef OBJECT_HH_
# define OBJECT_HH_

#include <vector>
#include <GL/glut.h>
#include "opengl.hh"
#include "vector.hh"
#include "quaternion.hh"

#define HSCL	150
#define VSCL	150
#define PSCL	500

#define HDCL	0.67
#define VDCL	0.34
#define PDCL	0.34

extern int verbose_p;
extern float	hscl; 
extern float	vscl;
extern float	pscl;
extern float	hdcl;
extern float	vdcl;
extern float	pdcl;

class Object
{
public:
  Object ()
  {
    _color[0] = 0.;
    _color[1] = 0.;
    _color[2] = 255.;
    _ps = 1.;
    
  }

  Object (vector<Vector3D> cloud) :
    _points(cloud)
  {
    _color[0] = 0.;
    _color[1] = 0.;
    _color[2] = 255.;
    _ps = 1.;
  }
  
  virtual ~Object () {}

  void add_point (Vector3D& vec)
  {
    _points.push_back (vec);
  }

  void add_point (double x, double y, double z)
  {
    _points.push_back (*new Vector3D(x, y, z));
  }

  void print(std::ostream& os) const
  {
    for (vector<Vector3D>::const_iterator i = _points.begin (); 
	 i != _points.end (); ++i)
      {
	(*i).print (os);
	os << std::endl;
      }
  }

  vector<Vector3D>& get_points (void)
  {
    return _points;
  }

  void	show (void) const
  {
    unsigned i;

    glClearColor(0., 0., 0., 0.);
    glPointSize(_ps);
    glBegin(GL_POINTS);
    glColor3d(_color[0], _color[1], _color[2]);
    for (i = 0; i < _points.size (); ++i)
      {
	glVertex3d (_points[i].getX () / hscl - hdcl, 
		    _points[i].getY () / vscl - vdcl, 
		    _points[i].getZ () / pscl - pdcl);
      }
    glEnd();
    glPointSize(10.);
    glBegin(GL_POINTS);
    glVertex3d (_bary.getX () / hscl - hdcl, 
		_bary.getY () / vscl - vdcl, 
		_bary.getZ () / pscl - pdcl);    

    glEnd();
  }

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
    if (verbose_p)
      {
	cout << "calcul du barycentre" << endl;
	cout << _bary << endl;
      }
  }

  Vector3D  getBarycentre(void) const
  {
    return _bary;
  }

  void  setBarycentre(Vector3D bary)
  {
    _bary = bary;
  }
  
  void	put_color(float r, float b, float g)
  {
    _color[0] = r;
    _color[1] = b;
    _color[2] = g;
  }
  
  void	setPointSize (float ps)
  {
    _ps = ps;
  }

  unsigned	getVectorSize (void)
  {
    return _points.size ();
  }

  virtual void	setError (float error)
  {
    _error = error;
  }

  virtual double	getError () const
  {
    return _error;
  }

  Object&	getMe (void)
  {
    return *this;
  }

protected:
  vector<Vector3D>	_points;
  Vector3D		_bary;
  float			_color[3];
  float			_ps;
  double		_error;
  
};

#endif
