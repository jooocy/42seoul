/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:42:57 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/25 21:17:16 by jojoo            ###   ########.fr       */
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

int		my_strlen(char *s1, char token);
char	*my_strjoin(char *s1, char *s2, int num);
char	*ft_split_join(char *s1, char *s2, t_list *lst_str);
int		my_strchr(const char *str, int to_find);
char	*load_backup(t_list **lst_buff, int fd);
char	*save_buff(t_list **lst_buff, char *str_buff, char *content);
char	*read_file(t_list **lst_buff, int fd, char *read_buff, char *road_data);
char	*ft_resave(t_list **lst_buff, char *str);
char	*get_next_line(int fd);
#endif