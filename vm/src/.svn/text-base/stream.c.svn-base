/*
** stream.c for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Jan  6 09:35:58 2002 jean-daniel michaud
** Last update Thu Jan 10 18:22:58 2002 jean-daniel michaud
*/

#include <stdio.h>

#include "my_struct.h"
#include "stream.h"
#include "debug.h"
#include "mem.h"
#include "my.h"

static t_dlist		*lwrite_op = NULL;

int			bwrite(t_vm		*vm,
			       t_process	*process,
			       unsigned int	addr,
			       unsigned short	quartet)
{
  t_write_op		*write_op;

  write_op = my_xmalloc(sizeof (t_write_op));
  write_op->process = process;
  write_op->addr = addr;
  write_op->quartet = quartet;
  dlist_put(&lwrite_op, write_op);
  return (1);
}

int			_flush(t_vm *vm)
{
  t_dlist		*route;
  t_write_op		*write_op;

  while ((lwrite_op && lwrite_op->next) && !resolve(vm))
    ;
  for (route = lwrite_op; route; route = route->next)
    {
      write_op = route->elem;
      _write_(vm, write_op->process, write_op->addr, write_op->quartet);
    }
  dlist_free(&lwrite_op);
  lwrite_op = 0;
  return (0);
}

int			resolve(t_vm *vm)
{
  t_dlist		*lactual;
  t_dlist		*lroute;
  t_dlist		*lcandidate;
  t_write_op		*actual;
  t_write_op		*route;
  short			first;

  for (lactual = lwrite_op, first = 1; lactual && lactual->next && first; )
    for (lroute = lactual->next, lcandidate = NULL, actual = lactual->elem; 
	 first && lroute; lroute = lroute->next)
      {
	route = lroute->elem;
	if (actual->addr == route->addr)
	  {
	    if (first)
	      dlist_put(&lcandidate, actual);
	    first = 0;
	    dlist_put(&lcandidate, route);
	  }
	if (!lcandidate)
	  lactual = lactual->next;
	else
	  return (vote(vm, lcandidate));
      }
  return (first);
}

int			vote(t_vm *vm, t_dlist *lcandidate)
{
  t_dlist		*route;
  t_write_op		*candidate;
  short			urn[2];
  unsigned short	res;
  unsigned short	actual;
  unsigned short	mask;

  res = actual = 0;
  candidate = lcandidate->elem;
  actual = _read_(vm, NULL, candidate->addr, &actual);
  for (mask = 1, urn[0] = urn[1] = 0; mask < 16; mask *= 2)
    {
      for (route = lcandidate; route; route = route = route->next)
	{
	  candidate = route->elem;
	  if (candidate->quartet & mask)
	    ++urn[1];
	  else
	    ++urn[0];
	}
      res |= elect(urn, mask, actual);
    }
  bwrite(vm, NULL, candidate->addr, res);
  dlist_free_from_list(&lwrite_op, lcandidate);
  return (1);
}

unsigned short		elect(short		urn[2],
			      unsigned short	mask,
			      unsigned short	actual)
{
  unsigned short	res;

  res = 0;
  if (urn[0] < urn[1])
    res |= mask;
  else
    if (urn[0] == urn[1])
      res |= (actual & mask);
  urn[0] = 0;
  urn[1] = 0;
  return (res);
}
