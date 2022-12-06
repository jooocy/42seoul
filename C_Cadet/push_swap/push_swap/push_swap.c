/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:37:42 by jojoo             #+#    #+#             */
/*   Updated: 2022/11/11 22:06:52 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_exit(char *error)
{
	write(2, error, ft_strlen(error));
	exit(1);
}

void	check_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && j == 0)
			{
				j++;
				continue ;
			}
			if (!ft_isdigit(argv[i][j]))
				ft_exit("Error\n");
			j++;
		}
		i++;
		j = 0;
	}
}

void	sort_id(t_master *stack_ma)
{
	t_node	*i;
	t_node	*j;

	i = stack_ma->head;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				i->id++;
			else if (i->value < j->value)
				j->id++;
			else
				ft_exit("Error\n");
			j = j->next;
		}
		i = i->next;
	}
}

int	is_sorted(t_master *stack_ma)
{
	t_node	*i;
	t_node	*j;

	i = stack_ma->head;
	while (i->next)
	{
		j = i->next;
		if (i->id > j->id)
			return (0);
		i = i->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_master	stack_ma;
	t_master	stack_mb;

	if (argc < 2)
		return (0);
	check_input(argc, argv);
	initialization(&stack_ma, &stack_mb, argc, argv);
	sort_id(&stack_ma);
	if (is_sorted(&stack_ma))
		ft_exit("");
	do_algorithm(&stack_ma, &stack_mb);
	exit(0);
}
