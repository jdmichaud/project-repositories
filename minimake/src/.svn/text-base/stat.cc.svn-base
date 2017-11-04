//
// stat.cc for minimake in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Fri Feb 22 13:36:10 2002 jean-daniel michaud
// Last update Sat Feb 23 15:20:39 2002 jean-daniel michaud
//

#include <sys/types.h>
#include <sys/stat.h>

#include "options.hh"
#include "stat.hh"

extern Option	opts;

bool	is_older(const string& first, const string& second)
{
  int	i;
  struct stat sb;
  
  lstat(first.data(), &sb);
  i = sb.st_mtime;
  lstat(second.data(), &sb);
  if (opts.Verbose())
    cout << i << " < " << sb.st_mtime << endl;
  return (i < sb.st_mtime);
}

bool	is_exist(const string& filename)
{
  struct stat sb;
  
  if (opts.Verbose())
    cout << filename << " exist ? : ";
  if (lstat(filename.data(), &sb) > -1)
    {
      if (opts.Verbose())
        cout << "YES" << endl;
      return (true);
    }
  if (opts.Verbose())
    cout << "NO" << endl;
  return (false);
}
