/*
** libstream.h for libstream in ~/c/rendu/libstream
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 11 08:33:31 2001 jean-daniel michaud
** Last update Mon Oct 22 14:18:09 2001 jean-daniel michaud
*/

#ifndef __LIBSTREAM_H_
# define __LIBSTREAM_H_

struct	s_my_file
{
  int	fd;

  void	*inbuf;
  void	*outbuf;
  int	inbuf_pos;
  int	outbuf_pos;

  long	offset;

  int	eof;
  int	right;
};

typedef	struct s_my_file	my_file;

my_file		*my_fopen(const char *path, const char *mode);
int		my_fclose(my_file *stream);
int		my_fputc(int c, my_file *stream);
int		my_fgetc(my_file *stream);
my_file		*my_fdopen(int fildes, const char *mode);
my_file		*my_freopen(const char	*path, 
			    const char	*mode, my_file *stream);
size_t		my_fread(void	*ptr, 
			 size_t	size, size_t nmemb, my_file *stream);
size_t		my_fwrite(const void	*ptr, 
			  size_t	size, size_t nmemb, my_file *stream);
char		*my_fgets(char *str, int size, my_file *stream);
int		my_fputs(const char *str, my_file *stream);
int		my_fseek(my_file *stream, long offset, int whence);
long		my_ftell(my_file *stream);
void		my_rewind(my_file *stream);
int		my_fgetpos(my_file *stream, fpos_t *pos);
int		my_fsetpos(my_file *stream, const fpos_t *pos);
int		my_fflush(my_file *stream);
int		my_fpurge(my_file *stream);
my_file		*create_file(int fd, int right);
void		tabcpy(char *dst, char *src, int size);
int		reload(my_file *stream);
int		my_strcmp(const char *s1, const char *s2);
int		my_isalpha(int c);
unsigned int	my_strlen(const char *str);

#endif
