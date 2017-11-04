//
// main.cc for math in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Wed Apr  3 10:14:23 2002 jean-daniel michaud
// Last update Thu May 30 20:30:36 2002 jean-daniel michaud
//

#include <iostream>
#include <list>
#include <GL/glut.h>
#include <getopt.h>
#include "quaternion.hh"
#include "parse.hh"
#include "vector.hh"
#include "opengl.hh"
#include "model.hh"
#include "cloud.hh"
#include "scene.hh"
#include "icp.hh"

#define PACKAGE "1"
#define VERSION "0.1"


char	*program_name;

// Les options
int opengl_p = 0;
int verbose_p = 0;
int error_p = 0;
int output_p = 0;
int input_p = 0;
int background_p = 0;
int rotation_p = 0;
int nosave_p = 0;
int force_p = 0;
int displayerr_p = 0;

string	path;

float	hscl = HSCL; 
float	vscl = VSCL;
float	pscl = PSCL;
float	hdcl = 0.;
float	vdcl = 0.;
float	pdcl = 0.;

extern "C"
{
#include "pgm.h"
}

using namespace std;

extern Scene	scene;

enum options_e
{
  opt_debug = 'd',
  opt_help = 'h',
  opt_version = 'V',
  opt_error = 'e',
  opt_output = 'o',
  opt_input = 'i',
  opt_use_ifexp = 257
};

static struct option const long_options[] =
{
  {"help",		no_argument,	0,			opt_help},
  {"version",		no_argument,	0,			opt_version},
  {"opengl",		no_argument,	&opengl_p,		1},
  {"verbose",		no_argument,	&verbose_p,		1},
  {"error",		required_argument,	&error_p,	opt_error},
  {"output",		no_argument,	&output_p,		1},
  {"input",		no_argument,	&input_p,		1},
  {"background",	no_argument,	&background_p,		1},
  {"rotation",		no_argument,	&rotation_p,		1},
  {"nosave",		no_argument,	&nosave_p,		1},
  {"force",		no_argument,	&force_p,		1},
  {"display-error",	no_argument,	&displayerr_p,		1},
  {NULL, 0, NULL, 0}
};

static const char short_options[] = "dhVeoi";

static void
usage (void)
{
  std::cerr << "Usage: " << program_name << " [OPTIONS] cloud_file pgm_file

Options:
  -h, --help                display this help and exit
  -V, --version             display the version and exit
      --opengl	            display the result in openGL 3D scene
      --verbose		    display the result in numeric mode
  -e, --error		    select the error limit
  -o <path>, --output	    output the result into <path>/cloud[n] 
                             and <path>/projection[n] files
  -i <path>, --input	    input the result from <path>/cloud[n] 
                             and <path>/projection[n] files (implies --opengl)
      --background          select de background points inthe pgm file
      --rotation	    apply a rotation during animation
      --nosave		    prevent saving during compute
      --force		    force compute to the limit
      --display-error       display the error on the openGL window"
	    << endl << endl;
  exit (0);
}

static void
version (void)
{
  std::cout << "math (" PACKAGE ") " VERSION << std::endl;
  std::cout
    << "Written by Botrom, Gizmo, JeDi." << std::endl;
  std::cout << std::endl;
  std::cout << "Copyleft 2002 EPITA." << std::endl;
  exit (0);
}


int	main(int argc, char *argv[])
{
  program_name = argv[0];
  double	limit = 2.;
  int c;

  while ((c = getopt_long (argc, argv, short_options, long_options,
  			   NULL)) != -1)
    {
      switch (c)
  	{
  	case opt_help:
  	  usage ();
  	  break;
  	case opt_version:
  	  version ();
  	  break;
	case opt_error:
	  limit = strtod (argv[optind++], NULL);
	  break;
	case opt_output:
	  output_p = 1;
	  path = argv[optind++];
	  break;
	case opt_input:
	  input_p = 1;
	  opengl_p = 1;
	  path = argv[optind++];
	  break;
  	}
    }

  pgm_init(&argc, argv);
  if (opengl_p)
    glutInit(&argc, argv);
  
  
  if (optind != argc - 2)
    {
      std::cerr << "usage: " << argv[0] << " cloud pgm_file" << std::endl;
      exit (1);
    }
  
  Parse parser(argv[optind], argv[optind + 1]);
  
  Cloud cloud(parser.parse_point());
  Model model = parser.generate_points();

  cloud.put_color (255., 0., 0.);
  cloud.setPointSize (2.);

  model.put_color (0.4, 0.4, 0.4);
  model.setPointSize (1.);
  model.calcBarycentre ();
  
  scene.add_cloud (cloud);
  scene.setModel (model);
  scene.arm ();
  
  if (input_p)
    scene.input (path + "/cloud", path + "/projection");
  else
    icp (limit);
  
  if (output_p)
    scene.output (path + "/cloud", path + "/projection");
  
  if (opengl_p)
    {
      open_window ();
      glutMainLoop();
    }

  return (0);
}
