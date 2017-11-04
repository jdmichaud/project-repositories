/*
** finger42.c for socket in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Dec 12 14:23:05 2001 jean-daniel michaud
** Last update Wed Dec 12 14:23:06 2001 jean-daniel michaud
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define	BUF_SIZE	4096

void    usage();
void	fconnect(int, char *, char *);


int	main(int argc, char *argv[])
{
  int	sd;
  char	buf[BUF_SIZE];

  if (argc < 4)
    {
      usage();
      return (-1);
    }
  if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      printf("Error: cannot create socket\n");
      return (-1);
    }
  fconnect(sd, argv[1], argv[2]);
  write(sd, argv[3], strlen(argv[3]));
  write(sd, "\n", 1);
  buf[read(sd, buf, BUF_SIZE)] = 0;
  close(sd);
  printf("%s\n", buf);
  return (0);
}

void	usage()
{
  printf("Usage:\n");
  printf("finger42 server port login\n");
  printf("\n");
}

void			fconnect(int fd, char *host, char *port)
{
  struct hostent	*hp;
  struct sockaddr_in    server;

  if ((hp = gethostbyname(host)) == NULL)
    {
      printf("Error: cannot resolve host\n");
      exit (-1);
    }
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(port));
  memcpy(&server.sin_addr.s_addr, hp->h_addr, hp->h_length);
  if ((connect(fd, (struct sockaddr *)&server, sizeof(server))) == -1)
    {
      perror("connect:");
      printf("Error: cannot connect to host\n");
      close(fd);
      exit(-1);
    }
}


