/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:55:58 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/16 21:17:47 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	load_backup(t_list **lst_buff, int fd)
{
	t_list	*temp;
	while ((*lst_buff)->next)
	{
		if ((*lst_buff)->fd == fd)
			return (0);
		(*lst_buff) = (*lst_buff)->next;
	}
	if ((*lst_buff)->fd == fd)
	(*lst_buff) = malloc(sizeof(t_list));
	if (!(*lst_buff))
		return (1);
	(*lst_buff)->fd = fd;
	(*lst_buff)->content = NULL;
	
	return (0);
}

char	*read_file(t_list **lst_buff)
{
	int		buff_size;
	char	*read_buff;

	read_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buff)
		return (0);
	while (1)
	{
		buff_size = read((*lst_buff)->fd, read_buff, BUFFER_SIZE);
		read_buff[buff_size] = '\0';
		if (buff_size < 0)
			break ;
		if (buff_size == 0)
		{
			if (!((*lst_buff)->content))
				return (0);
			return (ft_strjoin(lst_buff, read_buff));
		}
		(*lst_buff)->content = ft_strjoin(lst_buff, read_buff);
		if ((*lst_buff)->content == 0)
			return (0);
		if (ft_strchr((*lst_buff)->content, '\n'))
		{
			free(read_buff);
			return (save(lst_buff));
		}
	}
	free(read_buff);
	return (0);
}

int	remalloc(t_list **lst_buff)
{
	char	*temp;
	int		temp_size;
	int		new_line_len;
	int		i;

	new_line_len = ft_strlen((*lst_buff)->content, '\n') + 1;
	temp_size = ft_strlen((*lst_buff)->content, '\0') - new_line_len;
	temp = malloc(sizeof(char) * (temp_size));
	if (!temp)
		return (1);
	i = 0;
	while (i < temp_size)
		temp[i++] = (*lst_buff)->content[new_line_len++];
	temp[i] = '\0';
	if (!(*lst_buff)->content)
		free((*lst_buff)->content);
	(*lst_buff)->content = temp;
	return (0);
}

char	*save(t_list **lst_buff)
{
	char	*result;
	int		len;
	int		i;

	len = ft_strlen((*lst_buff)->content, '\n') + 1;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	i = -1;
	while (++i < len)
		result[i] = (*lst_buff)->content[i];
	result[i++] = '\0';
	if (remalloc(lst_buff))
	{
		free(result);
		return (0);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char			*result;
	static t_list	*lst_buff;
	
	if (BUFFER_SIZE < 0 || (fd > 0 && fd < 3) || fd < 0)
		return (0);
	if (load_backup(&lst_buff, fd))
		return (0);
	// printf("check: %s", lst_buff->content);
	// printf("end\n");
	if (ft_strchr(lst_buff->content, '\n'))
		return (save(&lst_buff));
	result = read_file(&lst_buff);
	return (result);
}
