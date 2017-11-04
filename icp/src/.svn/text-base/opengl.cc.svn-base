//
// opengl.cc for math in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sun May 19 14:49:10 2002 jean-daniel michaud
//

#include <vector.hh>
#include <list>
#include <GL/glut.h>
#include "opengl.hh"
#include "vector.hh"
#include "cloud.hh"
#include "model.hh"
#include "object.hh"
#include "scene.hh"

using namespace std;

extern Scene scene;
extern int verbose_p;
extern int rotation_p;
static unsigned val_tempo = 200;

void open_window (void)
{
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glEnable (GL_POINT_SMOOTH);
  glutInitWindowSize(640, 480);
  glutCreateWindow("math");
  glutDisplayFunc(redisplay);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutKeyboardFunc(keyb);
  glutIdleFunc(idle);

  gluPerspective(45.0, 1.0, 0.1, 20.0);
  gluLookAt(0.0, 0.0, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void	redisplay (void) 
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  scene.show ();
  glFlush();
  glutSwapBuffers ();
}

void mouse(int button, int state, int x, int y)
{
  /* si on appuie sur le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
      scene.lbtndown ();
      scene.setXmouse (x);
      scene.setYmouse (y);
    }
  if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
      scene.rbtndown ();
      scene.setXmouse (x);
      scene.setYmouse (y);
    }
  /* si on relache le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    scene.lbtnup ();
  if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
    scene.rbtnup ();
}

void motion(int x, int y)
{
  if (scene.getlBtn ())
    {
      //      glLoadIdentity();//
      scene.rotateX (x - scene.getXmouse ());
      scene.rotateY (y - scene.getYmouse ());
      glutPostRedisplay();
    }
  if (scene.getrBtn ())
    {
      //      glLoadIdentity();//
      scene.rotateX (x - scene.getXmouse ());
      scene.rotateZ (y - scene.getYmouse ());
      glutPostRedisplay();
    }
  scene.setXmouse (x);
  scene.setYmouse (y);
}

void		keyb (unsigned char touche, int x, int y)
{
  static bool	animate = true;

  switch (touche)
    {
    case 'a':
      if (animate)
      	{
	  glutIdleFunc(NULL);
      	  animate = false;
      	}
      else
      	{
	  glutIdleFunc(idle);
      	  animate = true;
      	}
      break;
    case 'q' : /*la touche 'q' permet de quitter le programme */
      exit(0);
    case 'n':
      cout << "affichage de l'iteration " << scene.next () << endl;
      scene.show ();
      redisplay();
      break;
    case 'm':
      scene.switchModel ();
      break;
    case 'c':
      scene.switchCloud ();
      break;
    case 'p':
      scene.switchProjection();
      break;
    case 'x':
      scene.swithExplicitProjection ();
      break;
    case '+':
      val_tempo -= 1000;
      break;
    case '-':
      val_tempo += 1000;
      break;
    case '8':
      scene.zoomIn ();
      break;
    case '2':
      scene.zoomOut ();
      break;
    case 'i':
      glLoadIdentity ();
      break;
    default:
      scene.keyup ();
    }
}

void	GLprintf (float x, float y, char *str)
{
  glRasterPos2f (x, y);
  for (int i = 0; str[i]; ++i)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, str[i]);
}

void	idle (void)
{
  static unsigned tempo = 0;

  if (tempo < val_tempo)
    ++tempo;
  else
    {    
      tempo = 0;
      scene.next ();
      scene.show ();
      redisplay();
    }
  if (rotation_p)
    {
      scene.rotateX (-0.008);
      scene.rotateY (0.01);
      scene.rotateZ (-0.005);
    }
}

