//
// opengl.hh for math in math
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sun May 19 14:51:42 2002 jean-daniel michaud
// Last update Thu May 30 12:15:27 2002 jean-daniel michaud
//

#ifndef OPENGL_H_QWERTY
# define OPENGL_H_QWERTY

#define HEIGHT	480
#define WIDTH	640

void	redisplay (void);
void	mouse(int button, int state, int x, int y);
void	motion(int x, int y);
void	keyb (unsigned char touche, int x, int y);
void	open_window (void);
void	GLprintf (float x, float y, char *str);
void	idle (void);

#endif
