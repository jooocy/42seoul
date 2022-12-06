/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:55:58 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/25 21:38:52 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*load_backup(t_list **lst_buff, int fd)
{
	if (!(*lst_buff))
	{
		(*lst_buff) = malloc(sizeof(t_list));
		(*lst_buff)->fd = fd;
		(*lst_buff)->content = NULL;
		return (0);
	}
	return ((*lst_buff)->content);
}

char	*save_buff(t_list **lst_buff, char *str_buff, char *content)
{
	char	*result;

	if (((*lst_buff)->content) != NULL)
		result = my_strjoin((*lst_buff)->content, str_buff, 1);
	else
		result = str_buff;
	result = ft_split_join(result, content, (*lst_buff));
	if ((*lst_buff)->content[0] == '\0')
	{
		free((*lst_buff)->content);
		free(*lst_buff);
		(*lst_buff) = NULL;
	}
	return (result);
}

char	*read_file(t_list **lst_buff, int fd, char *read_buff, char *road_data)
{
	int		buff_size;
	char	*str_buff;

	str_buff = malloc(1);
	if (!str_buff)
		return (0);
	str_buff[0] = '\0';
	while (1)
	{
		buff_size = read(fd, read_buff, BUFFER_SIZE);
		if (buff_size >= 0)
			read_buff[buff_size] = '\0';
		if (buff_size <= 0)
			break ;
		if (my_strchr(read_buff, '\n'))
			return (save_buff(lst_buff, str_buff, read_buff));
		str_buff = my_strjoin(str_buff, read_buff, 0);
	}
	str_buff = my_strjoin(road_data, str_buff, 2);
	free(*lst_buff);
	*lst_buff = NULL;
	return (str_buff);
}

char	*ft_resave(t_list **lst_buff, char *str)
{
	char	*result;
	int		i;
	int		j;

	j = -1;
	i = my_strlen(str, '\n') + 1;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (0);
	result[i] = '\0';
	while (++j < i)
		result[j] = str[j];
	i = -1;
	while (str[++i + j])
		str[i] = str[i + j];
	str[i] = '\0';
	if (i == 0)
	{
		free(str);
		free(*lst_buff);
		*lst_buff = NULL;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char			*read_buff;
	char			*result;
	static t_list	*lst_buff;
	char			*road_data;

	if (BUFFER_SIZE < 0 || (fd > 0 && fd < 3) || fd < 0)
		return (0);
	road_data = load_backup(&lst_buff, fd);
	if (my_strchr(road_data, '\n'))
		return (ft_resave(&lst_buff, road_data));
	read_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buff)
		return (0);
	result = read_file(&lst_buff, fd, read_buff, road_data);
	free(read_buff);
	return (result);
}
