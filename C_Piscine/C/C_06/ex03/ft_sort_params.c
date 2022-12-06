/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:36:59 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/21 13:44:52 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *a1, char *a2)
{
	int	i;

	i = 0;
	while (a1[i])
	{
		if (a1[i] != a2[i])
			return (a1[i] - a2[i]);
		i++;
	}
	if (a1[i] == a2[i])
		return (0);
	return (a1[i] - a2[i]);
}

void	sort(int index, char **mess)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < index - 1)
	{
		if (ft_strcmp(mess[i], mess[i + 1]) > 0)
		{
			temp = mess[i];
			mess[i] = mess[i + 1];
			mess[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	**order;

	order = av;
	i = 0;
	j = 0;
	if (ac > 1)
	{
		order++;
		sort(ac - 1, order);
		while (i < ac - 1)
		{
			while (order[i][j])
				j++;
			write(1, order[i], j);
			write(1, "\n", 1);
			j = 0;
			i++;
		}
	}
}
