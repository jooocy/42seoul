/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:13:11 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/26 02:12:09 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set(t_var *vars, int i, int j)
{
	if (vars->maps.map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.wall, \
			j * vars->images.size, i * vars->images.size);
	else if (vars->maps.map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.ground, \
			j * vars->images.size, i * vars->images.size);
	else if (vars->maps.map[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.player, \
			j * vars->images.size, i * vars->images.size);
	else if (vars->maps.map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->images.exit, \
			j * vars->images.size, i * vars->images.size);
	else if (vars->maps.map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->window, \
		vars->images.collector, j * vars->images.size, i * vars->images.size);
}

void	render(t_var *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->maps.height)
	{
		while (j < vars->maps.width)
		{
			set(vars, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}
