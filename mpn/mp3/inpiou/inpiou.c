/*
** inpiou.c for inpiou in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov  1 19:18:24 2001 jean-daniel michaud
** Last update Sat Nov  3 14:46:58 2001 jean-daniel michaud
*/

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "inpiou.h"

int	fisrt_son_action(int p[2], char **argv)
{
  int	fd;

  close(p[0]);
  dup2(p[1], 1);
  close(p[1]);
  if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
    exit(3);
  dup2(fd, 0);
  close(fd);
  execlp(argv[2], argv[2], NULL);
  if (errno == EACCES)
    exit(1);
  exit(2);
}

int	sec_son_action(int p[2], char **argv)
{
  int	fd;

  close(p[1]);
  dup2(p[0], 0);
  if ((fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
    exit(3);
  dup2(fd, 1);
  close(fd);
  execlp(argv[3], argv[3], NULL);
  if (errno == EACCES)
    exit(1);
  exit(2);
}

int	father_action(int pid1, int pid2)
{
  int	status1;

  wait(&status1);
  if ((WEXITSTATUS(status1) != 218) && WEXITSTATUS(status1))
    return (WEXITSTATUS(status1));
  return (0);
}

int	main(int argc, char **argv)
{
  int	p[2];
  int	first_pid;
  int	sec_pid;
  
  if (argc != 5)
    return (5);
  pipe(p);
  if ((first_pid = fork()))
    {
      if ((sec_pid = fork()))
	return (father_action(first_pid, sec_pid));
      else
	return (sec_son_action(p, argv));
    }
  else
    return (fisrt_son_action(p, argv));
  return (0);
}


