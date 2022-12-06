/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo42SEOUL.KR>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:38:39 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/13 16:38:43 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	check_correct_answer(char **result, char *col_row);

extern int	g_error;

void	free_memory(char ***result, char **col_row)
{
	int	i;

	i = 0;
	free(*col_row);
	*col_row = 0;
	while (i < 4)
	{
		free((*result)[i]);
		(*result)[i] = 0;
		i++;
	}
	free(*result);
	*result = 0;
}

void	print_result(char **result)
{
	int	i;
	int	j;

	if (g_error == 0)
		write(1, "\n", 1);
	g_error = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		write(1, &result[i][j++], 1);
		while (j < 4)
		{
			write(1, " ", 1);
			write(1, &result[i][j++], 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

void	get_result_recursive(char **result, char *col_row
		, char height, int depth)
{
	int	index;

	result[depth / 4][depth % 4] = height;
	index = (depth % 4) - 1;
	while (index >= 0)
	{
		if (result[depth / 4][index--] == height)
			return ;
	}
	index = (depth / 4) - 1;
	while (index >= 0)
	{
		if (result[index--][depth % 4] == height)
			return ;
	}
	if (depth == (16 - 1))
	{
		check_correct_answer(result, col_row);
		return ;
	}
	index = 0;
	while (index < 4)
		get_result_recursive(result, col_row, (index++) + '1', depth + 1);
}

int	malloc_memory(char ***result, char **col_row)
{
	int	i;

	*col_row = malloc(16 * sizeof(char));
	if (*col_row == 0)
		return (0);
	*result = malloc(4 * sizeof(char *));
	if (*result == 0)
		return (0);
	i = 0;
	while (i < 4)
	{
		(*result)[i] = malloc(4 * sizeof(char));
		if ((*result)[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

void	get_col_row(char *str)
{
	int		index;
	char	*col_row;
	char	**result;

	if (malloc_memory(&result, &col_row) == 0)
	{
		g_error = 1;
		return ;
	}
	index = 0;
	while (*str != '\0')
	{
		if (*str > '0' && *str <= '4')
			col_row[index++] = *str;
		str++;
	}
	index = 0;
	g_error = 1;
	while (index < 4)
		get_result_recursive(result, col_row, (index++) + '1', 0);
	free_memory(&result, &col_row);
}
