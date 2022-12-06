/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo42SEOUL.KR>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:38:22 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/13 16:38:30 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_result(char **result);

int	check_row_left(char **result, char *col_row, int start, int index)
{
	int		i;
	char	count;
	char	max;

	count = '0';
	max = '0';
	i = 0;
	while (i < 4)
	{
		if (max < result[index][i])
		{
			max = result[index][i];
			count++;
		}
		i++;
	}
	if (count != col_row[start + index])
		return (0);
	return (1);
}

int	check_row_right(char **result, char *col_row, int start, int index)
{
	int		i;
	char	count;
	char	max;

	count = '0';
	max = '0';
	i = 4 - 1;
	while (i >= 0)
	{
		if (max < result[index][i])
		{
			max = result[index][i];
			count++;
		}
		i--;
	}
	if (count != col_row[start + index])
		return (0);
	return (1);
}

int	check_col_down(char **result, char *col_row, int start, int index)
{
	int		i;
	char	count;
	char	max;

	count = '0';
	max = '0';
	i = 4 - 1;
	while (i >= 0)
	{
		if (max < result[i][index])
		{
			max = result[i][index];
			count++;
		}
		i--;
	}
	if (count != col_row[start + index])
		return (0);
	return (1);
}

int	check_col_up(char **result, char *col_row, int start, int index)
{
	int		i;
	char	count;
	char	max;

	count = '0';
	max = '0';
	i = 0;
	while (i < 4)
	{
		if (max < result[i][index])
		{
			max = result[i][index];
			count++;
		}
		i++;
	}
	if (count != col_row[start + index])
		return (0);
	return (1);
}

void	check_correct_answer(char **result, char *col_row)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (check_col_up(result, col_row, 0, i % 4) == 0)
			return ;
		if (check_col_down(result, col_row, (4 * 1), i % 4) == 0)
			return ;
		if (check_row_left(result, col_row, (4 * 2), i % 4) == 0)
			return ;
		if (check_row_right(result, col_row, (4 * 3), i % 4) == 0)
			return ;
		i++;
	}
	print_result(result);
}
