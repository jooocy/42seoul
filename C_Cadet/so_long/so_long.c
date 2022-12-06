/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:17:58 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/26 02:40:57 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./mlx/mlx.h"
#include "so_long.h"

void	check_file_name(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (find(&(file[i]), ".ber\0"))
				return ;
		}
		i++;
	}
	write(2, "wrong name", 10);
	exit(1);
}

void	handle_movement(t_var *vars, int next_i, int next_j)
{
	int	i;
	int	j;

	i = vars->games.player_i;
	j = vars->games.player_j;
	if (next_i < 0 || next_i >= vars->maps.height)
		return ;
	if (next_j < 0 || next_j >= vars->maps.width)
		return ;
	if (vars->maps.map[next_i][next_j] == '1')
		return ;
	if (vars->maps.map[next_i][next_j] == 'E')
	{
		if (vars->games.collector == 0)
			exit(0);
		else
			return ;
	}
	if (vars->maps.map[next_i][next_j] == 'C')
		vars->games.collector--;
	vars->maps.map[next_i][next_j] = 'P';
	vars->maps.map[i][j] = '0';
	vars->games.player_i = next_i;
	vars->games.player_j = next_j;
	vars->games.movement++;
}

int	close_game(t_var *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	exit(0);
}


int	key_press(int keycode, t_var *vars)
{
	int	next_i;
	int	next_j;

	next_i = vars->games.player_i;
	next_j = vars->games.player_j;
	if (keycode == KEY_W)
		next_i = vars->games.player_i - 1;
	else if (keycode == KEY_S)
		next_i = vars->games.player_i + 1;
	else if (keycode == KEY_A)
		next_j = vars->games.player_j - 1;
	else if (keycode == KEY_D)
		next_j = vars->games.player_j + 1;
	else if (keycode == KEY_ESC)
		exit(0);
	if (next_i != vars->games.player_i || next_j != vars->games.player_j)
		handle_movement(vars, next_i, next_j);
	render(vars);
	printf_map(vars);
	printf("x: %d, y: %d move: %d col: %d\n", vars->games.player_j, \
	vars->games.player_i, vars->games.movement, vars->games.collector);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	vars;

	printf("%d\n", argc);
	if (argc != 2)
	{
		write(2, "error\n", 6);
		exit(1);
	}
	check_file_name(argv[1]);
	get_maps(argv[1], &vars);
	check_maps(&vars);
	printf("4\n");
	init_vars(&vars);
	render(&vars);
	printf("5\n");
	mlx_hook(vars.window, X_EVENT_KEY_RELEASE, 0, &key_press, &vars);
	mlx_hook(vars.window, X_EVENT_KEY_EXIT, 0, &close_game, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
