//
// execpt.hh for minimake in 
// 
// Made by Jean-Daniel Michaud
// Login   <JeDi@epita.fr>
// 
// Started on  Thu Feb 21 18:53:54 2002 Jean-Daniel Michaud
// Last update Sun Feb 24 12:00:35 2002 jean-daniel michaud
//

#ifndef EXCEPT_HH_
# define EXCEPT_HH_

class Except {};
class Cycle : public Except 
{
public:
  Cycle(const string& rule) : _rule(rule) {}
  ~Cycle() {}
  
  string	_rule;
};

class UknRule : public Except 
{
public:
  UknRule(const string& file) : _file(file) {}
  ~UknRule() {}

  string	_file;
};

#endif /* !EXCEPT_HH_ */
