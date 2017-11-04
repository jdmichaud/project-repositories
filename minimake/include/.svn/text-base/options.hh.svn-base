//
// options.hh for minimake in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sun Feb 17 13:27:11 2002 jean-daniel michaud
// Last update Sat Feb 23 15:33:46 2002 jean-daniel michaud
//

#ifndef OPTIONS_HH_
# define OPTIONS_HH_

#include <string>
#include <vector>

using namespace std;

#define NBOPTS		4

class Option
{
public:
  Option() : _small(0), _name("Makefile"), _rule("all"), _rule_specify(false)
  {
  }

  void		Get(unsigned int argc, char **argv);
  void		PutName(const char *name);
  void		PutRule(const char *name) { _rule = name; }
  void		PutTrace(void);
  void		PutVerbose(void);
  void		Version(void);

  bool		NameSpecify(void) const;
  string	GetName(void) const;
  bool		GetTrace(void) const;
  string	GetRule(void) const { return (_rule); }
  bool		Verbose(void) const { return (_small & 4); }
  bool		IsRuleSpecify(void) const { return (_rule_specify); }

private:

  // -f = small & 8
  // --version = small & 1
  // --trace-parse = small & 2
  // --verbose = small & 4

  int		_small;
  string	_name;
  string	_rule;
  bool		_rule_specify;
};

typedef struct				s_option
{
  string				name;
  string				longname;
  unsigned short			nbarg;
}					t_option;

#endif /* !OPTIONS_HH_ */
