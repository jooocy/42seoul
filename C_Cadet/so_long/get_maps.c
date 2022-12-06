/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:29:43 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/26 02:08:49 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	get_maps(char *file, t_var *vars)
{
	int		fd;
	char	*line;
	char	*all_lines;

	fd = open(file, O_RDONLY);
	vars->maps.height = 0;
	all_lines = malloc(1);
	if (!all_lines)
		exit(1);
	all_lines[0] = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		vars->maps.height++;
		free(line);
	}
	vars->maps.map = ft_split(all_lines, '\n');
	if (vars->maps.map == NULL)
		exit(1);
	vars->maps.width = ft_strlen(vars->maps.map[0]);
	printf_map(vars);
}
