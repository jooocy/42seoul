/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:31:06 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/26 02:10:42 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collector(t_var *vars)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 0;
	result = 0;
	while (i < vars->maps.height)
	{
		while (j < vars->maps.width)
		{
			if (vars->maps.map[i][j] == 'C')
				result++;
			if (vars->maps.map[i][j] == 'P')
			{
				vars->games.player_i = i;
				vars->games.player_j = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (result);
}

void	set_images(t_var *vars)
{
	vars->images.size = 15;
	vars->images.collector = mlx_xpm_file_to_image(vars->mlx, \
	"./images/collector.xpm", &vars->images.size, &vars->images.size);
	vars->images.ground = mlx_xpm_file_to_image(vars->mlx, \
	"./images/ground.xpm", &vars->images.size, &vars->images.size);
	vars->images.player = mlx_xpm_file_to_image(vars->mlx, \
	"./images/player.xpm", &vars->images.size, &vars->images.size);
	vars->images.exit = mlx_xpm_file_to_image(vars->mlx, \
	"./images/exit.xpm", &vars->images.size, &vars->images.size);
	vars->images.wall = mlx_xpm_file_to_image(vars->mlx, \
	"./images/wall.xpm", &vars->images.size, &vars->images.size);
}

void	init_vars(t_var *vars)
{
	vars->games.collector = count_collector(vars);
	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, vars->maps.width * 16, \
	vars->maps.height * 15, "so_long");
	set_images(vars);
}
