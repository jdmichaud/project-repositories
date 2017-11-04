//
// main.cc for quaternion in 
// 
// Made by Jean-Daniel Michaud
// Login   <JeDi@epita.fr>
// 
// Started on  Fri Feb  1 15:12:30 2002 Jean-Daniel Michaud
// Last update Thu Feb 14 18:13:04 2002 jean-daniel michaud
//

#include <iostream>
#include <vector>

#include "quaternion.hh"
#include "matrix.hh"
#include "slerp.hh"

// On recupere le nombre d'interpolation,
// les differents quaternion,
// et on effectue les interpolation entre quaternions.

int			main(int argc, char **argv)
{
  unsigned int		nbi = 0;
  unsigned int		i = 0;
  unsigned int		j = 0;
  bool			ok = 0;
  Quaternion		q;
  vector<Quaternion>	v;

  cin >> nbi;
  assert(nbi > 0);
  while (cin >> q)
    {
      v.push_back(q);
      ok = 1;
    }
  for (i = 0; i < v.size() - 1; ++i)
    {
      cout << Quat2Mat(v[i]);
      cout << endl;
      for (j = 1; j < nbi; ++j)
	{
	  q = slerp(v[i], v[i + 1], ((float) j / (float) nbi));
	  cout << Quat2Mat(q);
	  cout << endl;
	}
    }
  cout << Quat2Mat(v[i]);  
  return (0);
}
