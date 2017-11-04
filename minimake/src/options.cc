//
// options.cc for minimake in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sun Feb 17 13:31:47 2002 jean-daniel michaud
// Last update Sun Feb 24 11:58:37 2002 jean-daniel michaud
//

#include <iostream>
#include <string.h>
#include "options.hh"
#include "common.hh"

static const t_option	options[] =
{
  {"-f", "--file", 1},
  {"-t", "--trace-parse", 0},
  {"-e", "--verbose", 0},
  {"-v", "--version", 0},
  {"", "", 0}
};

void			Option::Get(unsigned int argc, char **argv)
{
  unsigned short	i;
  unsigned short	j;

  for (i = 1; i < argc; ++i)
    {
      for (j = 0; (j < NBOPTS) 
	     && (strcmp(argv[i], options[j].name.data()))
	     && strcmp(argv[i], options[j].longname.data()); ++j)
	;
      if (j < NBOPTS)
	{
	  switch (j)
	    {
	    case 0:
	      ++i;
	      assert(argv[i] != NULL);
	      PutName(argv[i]);
	      break;
	    case 1: 
	      PutTrace();
	      break;
	    case 2:
	      cout << "put verbose" << endl;
	      PutVerbose();
	      break;
	    case 3:
	      Version();
	      break;
	    }
	}
      else
	{
	  assert(argv[i] != NULL);
	  if (argv[i][0] == '-')
	    {
	      cout << BAD_OPTIONS << argv[i] << endl;
	      exit(EXIT_STATUS_BAD_OPTIONS);
	    }
	  else
	    {
	      PutRule(argv[i]);
	      _rule_specify = true;
	    }
	}
    }
}

void		Option::PutName(const char *name)
{
  _name = name;
  _small |= 8;
}

void		Option::PutTrace(void)
{
  _small |= 2;
}

void		Option::PutVerbose(void)
{
  _small |= 4;
}

void		Option::Version(void)
{
  _small |= 1;
  cout << VERSION;
  exit(EXIT_STATUS_VERSION);
}

bool		Option::NameSpecify(void) const
{
  return (_small & 8);
}

string		Option::GetName(void) const
{
  return (_name);
}

bool		Option::GetTrace(void) const
{
  return (_small & 2);
}
