/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:42:57 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/12 21:43:37 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	int				fd;
	struct s_list	*next;
}	t_list;

int		load_backup(t_list **lst_buff, int fd);
char	*read_file(t_list **lst_buff);
int		remalloc(t_list **lst_buff);
char	*save(t_list **lst_buff);
char	*get_next_line(int fd);
int		ft_strlen(char *s1, char token);
int		ft_strchr(const char *str, int to_find);
char	*ft_strjoin(t_list **lst_buff, char *s2);
#endif
