/*
** mydef.h for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Tue Oct 30 17:16:33 2001 GIZMO
** Last update Fri Jan 11 16:55:32 2002 jean-daniel michaud
*/

#ifndef MYDEF_H_
# define MYDEF_H_

#include "data.h"

/*#define DEBUG___*/

#define FALSE		0
#define TRUE		1

#define QSIZE		4

#define MAX_PROC	2048
#define MAX_SIZE_CMD	200
#define REG_PC		16
#define REG_Z		17
#define REG_P		17

#define VAL_PC		16
#define VAL_Z		17
#define VAL_P		18

#define	MAX_OPTS       	12

#define	USAGE		"usage: kvm [-help] [-ms n] [-mp n] [-im n] [-cy n]" \
			" [-nl n] [-cd n] [-t] [-v] [-g n] [-interface]" \
			" [file 1 ...[file n]]\n"

#define MAX_SIZE_CMD	200

#define SUICIDE		2
#define DIED		1
#define LIVING		0

#define READY		0

#define NO_FOLLOW	43

#define DO_DEC_DELTA	1
#define DONT_DEC_DELTA	0

#define VERBOSE		1
#define NO_VERBOSE	0

#define NO_DEBUG	0

#define	NO_DELAY	0

#define CDB_ON		1
#define CDB_OFF		0

#define EPITAPHE	"process %u havn't say live for many time\n"

#endif /* MYDEF_H_ */ 



