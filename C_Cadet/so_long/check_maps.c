/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:52:05 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/26 02:08:27 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular(t_var *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->maps.map[i])
	{
		while (vars->maps.map[i][j++])
			;
		if (j - 1 != vars->maps.width)
			exit(1);
		j = 0;
		i++;
	}
	if (i != vars->maps.height)
		exit(1);
}

void	check_walls(t_var *vars)
{
	int	i;

	i = 0;
	while (i < vars->maps.width)
	{
		if (vars->maps.map[0][i] != '1')
			exit(1);
		if (vars->maps.map[(vars->maps.height) - 1][i] != '1')
			exit(1);
		i++;
	}
	i = 0;
	while (i < vars->maps.height)
	{
		if (vars->maps.map[i][0] != '1')
			exit(1);
		if (vars->maps.map[i][(vars->maps.width) - 1] != '1')
			exit(1);
		i++;
	}
}

void	check_elements(t_var *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->maps.height)
	{
		while (j < vars->maps.width)
		{
			if (vars->maps.map[i][j] != '1' && vars->maps.map[i][j] != 'C' && \
			vars->maps.map[i][j] != 'E' && vars->maps.map[i][j] != 'P'\
			&& vars->maps.map[i][j] != '0')
				exit(1);
			j++;
		}
		i++;
	}
}
void	printf_map(t_var *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("%d %d\n", vars->maps.height, vars->maps.width);
	while (i < vars->maps.height)
	{
		while (j < vars->maps.width)
		{
			printf("%c", vars->maps.map[i][j]);
			j++;
		}
		i++;
		j = 0;
		printf("\n");
	}
}

void	check_maps(t_var *vars)
{
	check_rectangular(vars);
	printf("b\n");
	check_walls(vars);
	printf("a\n");
	check_elements(vars);
	printf("b\n");

}
