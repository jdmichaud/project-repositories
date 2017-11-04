#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

void do_job(int fd);

int			main(int argc, char *argv[])
{
  int			toto;
  int			fd, fd_client;
  struct sockaddr_in    sock, client;

  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
      printf("Cannot create socket\n");
      return (-1);
    }
  sock.sin_family = PF_INET;
  sock.sin_port = htons(3000);
  sock.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (struct sockaddr *)&sock, sizeof(struct sockaddr_in)) == -1)
     {
      printf("Cannot bind\n");
      exit (-1);
    }
  if (listen(fd, 5) == -1)
     {
      printf("Cannot listen\n");
      exit (-1);
    }
  toto = sizeof(struct sockaddr_in);
  while (1)
    {
      fd_client = accept(fd, (struct sockaddr *)&client, &toto);
      if (fork())
	close (fd_client);
      else
	do_job(fd_client);
    }
  return (0);
}


void do_job(int fd)
{
  write(fd, "salut\n", 6);
  close (fd);
  exit (0);
}
