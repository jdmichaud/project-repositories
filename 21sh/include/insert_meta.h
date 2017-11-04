/*
** insert_meta.h for  in
** 
** Made by (Florent Monbillard)
** Login   <monbil_f@epita.fr>
** 
** Started on  Mon Dec 31 07:29:22 2001 Florent Monbillard
** Last update Mon Dec 31 08:12:15 2001 Florent Monbillard
*/

#ifndef   INSERT_META_H_
# define   INSERT_META_H_

char	**xmetachar(t_command *cmd, int pos);
int	insert_meta_in_cmd(t_command *cmd, int pos);

#endif /* INSERT_META_H_ */
