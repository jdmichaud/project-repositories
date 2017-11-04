//
// scene.hh for math in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Mon May 20 13:24:22 2002 jean-daniel michaud
//

#ifndef SCENE_HH_
# define SCENE_HH_

#include <vector>
#include <list>
#include <map>
#include <fstream.h>
#include <GL/glut.h>
#include <assert.h>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include "opengl.hh"
#include "vector.hh"
#include "matrix.hh"
extern "C"
{
#include "math.h"
}

extern int verbose_p;
extern int displayerr_p;

extern float	hscl; 
extern float	vscl;
extern float	pscl;
extern float	hdcl;
extern float	vdcl;
extern float	pdcl;

class Scene
{
public:
  Scene () :
    _projection_switch(true),
    _model_switch(true),
    _cloud_switch(true),
    _explicit_projection_switch(true),
    _height(480),
    _width(640), 
    _lbtn(false),
    _rbtn(false),
    _mouseX(0),
    _mouseY(0),
    _distance(2.5)
  {}


  /*
  ** Creation et ajout des nuages
  */
  void	add_cloud (Cloud& c)
  {
    c.calcBarycentre ();
    _clouds.push_back (c);
  }

  void	setModel (Model& m)
  {
    _model = m;
  }

  /*
  ** Affichage
  */
  void	arm (void)
  {
    _current_cloud = _clouds.begin ();
    _current_projection = _projection.begin ();
  }

  void		show (void)
  {
    if (_model_switch)
      _model.show ();
    if (_cloud_switch)
      (*_current_cloud).show ();
    if (_projection_switch)
      (*_current_projection).show ();
    if (_explicit_projection_switch)
      showProjection ();

    if (displayerr_p)
      {
	char	*err;

	glColor3d(0., 0.6, 0.2);
	err = new char[255];
	sprintf (err, "%f",  (*_current_cloud).getError ());
	GLprintf (-0.7, -0.7, err);
	delete[] err;
      }
  }

  void		showProjection (void)
  {
    vector<Vector3D> cl = (*_current_cloud).get_points ();
    vector<Vector3D> pr = (*_current_projection).get_points ();

    for (unsigned i = 0; (i < cl.size ()) && (i < pr.size ()); ++i)
      {
	glBegin(GL_LINES);
	glColor3f (255., 255., 255.);
	glVertex3f (cl[i].getX () / hscl - hdcl,
		    cl[i].getY () / vscl - vdcl, 
		    cl[i].getZ () / pscl - pdcl); 
	glVertex3f (pr[i].getX () / hscl - hdcl, 
		    pr[i].getY () / vscl - vdcl, 
		    pr[i].getZ () / pscl - pdcl); 
	glEnd ();
      }
  }

  unsigned	next (void)
  {
    list<Object>::const_iterator	tmp;
    static unsigned			it = 0;

    tmp = _current_cloud;
    ++tmp;
    if (tmp == _clouds.end ())
      {
	_current_cloud = _clouds.begin ();
	_current_projection = _projection.begin ();
	it = 0;
      }
    else
      {
	++_current_cloud;
	++it;
      }

    tmp = _current_projection;
    ++tmp;
    if (tmp != _projection.end ())
      ++_current_projection;

    return it;
  }

  void	switchModel (void)
  {
    if (verbose_p)
      if (_model_switch)
	cout << "hiding model" << endl;
      else
	cout << "showing model" << endl;	
    _model_switch = !_model_switch;
  }

  void	switchCloud (void)
  {
    if (verbose_p)
      if (_cloud_switch)
	cout << "hiding cloud" << endl;
      else
	cout << "showing cloud" << endl;	
    _cloud_switch = !_cloud_switch;
  }

  void	switchProjection (void)
  {
    if (verbose_p)
      if (_projection_switch)
	cout << "hiding projection" << endl;
      else
	cout << "showing projection" << endl;	
    _projection_switch = !_projection_switch;
  }

  void	swithExplicitProjection (void)
  {
    if (verbose_p)
      if (_projection_switch)
	cout << "hiding explicit projection" << endl;
      else
	cout << "showing explicit projection" << endl;	
    _explicit_projection_switch = !_explicit_projection_switch;
  }

  void	zoomIn (void)
  {
    hscl += 20;
    vscl += 20;
    pscl += 50;
  }

  void zoomOut (void)
  {
    hscl -= 20;
    vscl -= 20;
    pscl -= 50;
  }

  /*
  ** Accesseurs
  */
  void	rotateX(float angle)
  {
    glRotatef(- angle / 2, 1.0, 0.0, 0.0);
  }

  void	rotateY(float angle)
  {
    glRotatef(angle / 2, 0.0, 1.0, 0.0);
  }

  void	rotateZ(float angle)
  {
    glRotatef(angle / 2, 0.0, 0.0, 1.0);
  }

  void	reorient (void)
  {
    rotateX (10);
    rotateY (10);    
    rotateZ (-240);    
  }

  void	lbtndown (void)
  {
    _lbtn = true;
  }

  void	lbtnup (void)
  {
    _lbtn = false;
  }
  void	rbtndown (void)
  {
    _rbtn = true;
  }

  void	rbtnup (void)
  {
    _rbtn = false;
  }

  void	setXmouse (int x)
  {
    _mouseX = x;
  }

  void	setYmouse (int y)
  {
    _mouseY = y;
  }

  int	getXmouse (void)
  {
    return _mouseX;
  }

  int	getYmouse (void)
  {
    return _mouseY;
  }

  bool	getlBtn (void)
  {
    return (_lbtn);
  }
  
  bool	getrBtn (void)
  {
    return (_rbtn);
  }

  void	keydown (void)
  {
    _key = true;
  }

  void	keyup (void)
  {
    _key = false;
  }

  bool	getkey (void)
  {
    return _key;
  }

  unsigned	getIterationNbr (void)
  {
    return _projection.size ();
  }

  Object& getFirstCloud (void)
  {
    list<Object>::iterator i = _clouds.begin ();

    return ((*i).getMe ());
  }

  /*
  ** Algo et fonctions principales
  */
  void	getNearestList ()
  {
    vector<Vector3D> xi = _model.get_points ();
    vector<Vector3D> pi = (_clouds.back ()).get_points ();
    Object		projection;
    int			j;

    for (unsigned i = 0; i < pi.size (); ++i)
      {
	j = pi[i].getNearest (xi);
	projection.add_point (xi[j]);
      }
    projection.calcBarycentre ();
    projection.put_color (0., 255., 0.);
    _projection.push_back (projection);
  }

  Matrix	covariance()
  {
    vector<Vector3D> xi = _model.get_points ();
    vector<Vector3D> pi = (_clouds.back ()).get_points ();
    vector<Vector3D> projection = (_projection.back ()).get_points ();

    Vector3D		mux = _model.getBarycentre ();
    Vector3D		mup = (_clouds.back ()).getBarycentre ();
    Matrix		res;

    if (projection.size () == 0)
      return res;
    for (unsigned int i = 0; i < pi.size (); ++i)
      res = res + (pi[i] - mup) * (projection[i] - mux);
    res = res / pi.size ();
    return (res);
  }

  void match (const Quaternion& Q)
  {
    vector<Vector3D> pi = (_clouds.back ()).get_points ();
    vector<Vector3D> projection = (_projection.back ()).get_points ();
    Vector3D		new_point;

    Matrix rot = quat2mat (Q);

    if (verbose_p)
      cout << "Matrice de rotation :" << endl << rot << endl;

    Vector3D trans = (_projection.back ()).getBarycentre () - 
      (rot * (_clouds.back ()).getBarycentre ());

    cout << "Quaternion de rotation: ";
    Q.print (cout);
    cout << endl;
    cout << "Quaternion de translation: ";
    trans.print (cout);
    cout << endl;

    Cloud newCloud;
    newCloud.put_color (255., 0., 0.);
    for (unsigned i = 0; i < pi.size (); ++i)
      {
	new_point = (rot * pi[i]) + trans;
	newCloud.add_point (new_point);
      }
    newCloud.setPointSize (2.);
    //    newCloud.setError (error (newCloud.get_points ()));//
    add_cloud (newCloud);
  }

  double	error (void)
  {
    vector<Vector3D> pi = (_clouds.back ()).get_points ();
    vector<Vector3D> projection = (_projection.back ()).get_points ();
    double	err = 0.;
    double	tmp;

    for (unsigned i = 0; i < pi.size (); ++i)
      {
	tmp = (projection[i] - pi[i]).norme ();
	tmp *= tmp;
	err += tmp;
      }
    err /= pi.size ();
    return err;
  }

  double	error (const vector<Vector3D>& pi)
  {
    assert (_projection.size () != 0);

    vector<Vector3D> projection = (_projection.back ()).get_points ();
    double	err = 0.;
    double	tmp;

    for (unsigned i = 0; i < pi.size (); ++i)
      {
	tmp = (projection[i] - pi[i]).norme ();
	tmp *= tmp;
	err += tmp;
      }
    err /= pi.size ();
    return err;
  }

  void		output (const string& cloudsFilename, 
			const string& projectionsFilename)
  {
    list<Object>::iterator	clouds = _clouds.begin ();
    list<Object>::iterator	projections = _projection.begin ();
    
    ++clouds;
    for (unsigned i = 1; clouds != _clouds.end (); 
	 ++i, ++clouds, ++projections)
      {
	stringstream	indice;
	indice << i;
	ofstream	cloudFile ((cloudsFilename + indice.str ()).c_str ());
	ofstream	projectionFile 
	  ((projectionsFilename + indice.str ()).c_str ());
	
	cout << "--> " << (cloudsFilename + indice.str ()) << endl;
	cout << "--> " << (projectionsFilename + indice.str ())<< endl;
	vector<Vector3D> pi = (*clouds).get_points ();
	vector<Vector3D> projection = (*projections).get_points ();
	for (unsigned n = 0; n < pi.size (); ++n)
	  {
	    cloudFile << pi[n].getX () << " "
		      << pi[n].getY () << " "
		      << pi[n].getZ () << " " << endl;
	    projectionFile << projection[n].getX () << " "
			   << projection[n].getY () << " "
			   << projection[n].getZ () << " " << endl;
	  }
      }
  }

  void		input (const string& cloudsFilename, 
		       const string& projectionsFilename)
  {
    ifstream	cloudFile ((cloudsFilename + "1").c_str ());
    ifstream	projectionFile 
      ((projectionsFilename + "1").c_str ());

    for (unsigned i = 2; cloudFile.is_open () 
	   && projectionFile.is_open (); ++i)
      {
	stringstream	indice;
	Cloud		cloud;
	Object		projection;
	double		x, y, z;
	
	indice << i;
	cout << "<-- " << (cloudsFilename + indice.str ()) << endl;
	cout << "<-- " << (projectionsFilename + indice.str ())<< endl;

	while (!cloudFile.eof () && !projectionFile.eof ())
	  {
	    cloudFile >> x >> y >> z;
	    cloud.add_point (x, y, z);
	    projectionFile >> x >> y >> z;
	    projection.add_point (x, y, z);
	  }
	projection.calcBarycentre ();
	projection.put_color (0., 255., 0.);
	_projection.push_back (projection);

	cloud.put_color (255., 0., 0.);
	cloud.setPointSize (2.);
	cloud.setError (error (cloud.get_points ()));
	add_cloud (cloud);

	cloudFile.close ();
	projectionFile.close ();

	cloudFile.clear ();
	projectionFile.clear ();

	cloudFile.open ((cloudsFilename + indice.str ()).c_str ());
	projectionFile.open ((projectionsFilename + indice.str ()).c_str ());
      }
    cout << "Nombre de nuages: " << _clouds.size () << endl;
    cout << "Nombre de projections: " << _projection.size () << endl;
  }

private:
  Object		_model;
  list<Object>		_clouds;
  list<Object>		_projection;

  list<Object>::iterator	_current_cloud;
  list<Object>::iterator	_current_projection;

  bool			_projection_switch;
  bool			_model_switch;
  bool			_cloud_switch;
  bool			_explicit_projection_switch;

  unsigned		_height;
  unsigned		_width;
  bool			_lbtn;
  bool			_rbtn;
  int			_mouseX;
  int			_mouseY;
  bool			_key;
  double		_distance;

};

#endif
