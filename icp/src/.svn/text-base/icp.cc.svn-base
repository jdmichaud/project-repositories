//
// icp.cc for math in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Wed May 29 15:36:40 2002 jean-daniel michaud
// Last update Thu May 30 20:38:18 2002 jean-daniel michaud
//

#include <iostream>
#include "vector.hh"
#include "matrix.hh"
#include "icp.hh"
#include "model.hh"
#include "cloud.hh"
#include "scene.hh"

extern int opengl_p;
extern int verbose_p;
extern int error_p;
extern int output_p;
extern int input_p;
extern int background_p;
extern int rotation_p;
extern int nosave_p;
extern int force_p;

extern string	path;

Scene	scene;

void		stop (void)
{
  static bool	done = false;
  static float	last_error = 0.;

  float error = scene.error ();

  cout << "Erreur quadratique: " << error << endl;
  if (!nosave_p && !done && (last_error != 0.) && (error > 1.) 
      && ((last_error - error) < LIMIT))
    {
      if (force_p)
	{
	  done = true;
	  if (output_p)
	    {
	      cout << "le calcul ne semble pas se terminer, sauvegarde ..."
		   << endl;
	      scene.output (path + "/cloud", path + "/projection");
	    }
	}
      else
	{
	  cout << "Le calcul semble ne pas converger vers la limite, stop" 
	       << endl;
	  exit (1);
	}
    }
  last_error = error;
}

void	icp (double limit)
{
  static Matrix Identity (1., 0., 0.,
			  0., 1., 0.,
			  0., 0., 1.);

  cout << "Limite: " << limit << endl; 
  do
    {
      scene.getNearestList ();
      scene.getFirstCloud (). setError 
	(scene.error (scene.getFirstCloud ().get_points ()));

      //      newCloud.setError (error (newCloud.get_points ()));//

      Matrix Ck = scene.covariance ();
      if (verbose_p)
	{
	  cout << "Matrice de covariance croisee: " << endl;
	  Ck.print (cout);
	}
      Matrix Ak = Ck - Ck.transpose ();
      if (verbose_p)
	{
	  cout << "Matrice Ak: " << endl;
	  Ak.print (cout);
	}
      Vector3D Delta (Ak.get (1, 2), Ak.get (2, 0), Ak.get (0, 1));
      if (verbose_p)
	{      
	  cout << "Vecteur Delta: " << endl;
	  Delta.print (cout);
	  cout << endl;
	}
      Matrix Qp = Ck + Ck.transpose () - (Identity * Ck.trace ());
      Matrix4x4 Q (Ck.trace (), Delta.getX (), Delta.getY (), Delta.getZ (),
		   Delta.getX (), Qp.get(0, 0), Qp.get(0, 1), Qp.get(0, 2),
		   Delta.getY (), Qp.get(1, 0), Qp.get(1, 1), Qp.get(1, 2),
		   Delta.getZ (), Qp.get(2, 0), Qp.get(2, 1), Qp.get(2, 2));

      if (verbose_p)
	{      
	  cout << "Matrice Q: " << endl;
	  Q.print (cout);
	}      

      vector<double> vec = Q.CalculVecteur();
      Quaternion quat (vec[1], vec[2], vec[3], vec[0]);

      scene.match (quat);
      
      stop ();
    }
  while (scene.error () > limit);
  cout << "Arret apres " << scene.getIterationNbr () << " iterations" 
       << endl;
}
