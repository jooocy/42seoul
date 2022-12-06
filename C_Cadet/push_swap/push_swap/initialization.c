/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:58:50 by jojoo             #+#    #+#             */
/*   Updated: 2022/11/11 22:21:03 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	initialization(t_master *stack_ma, t_master *stack_mb, \
int argc, char **argv)
{
	init_master(stack_ma);
	init_master(stack_mb);
	push_data_stack_a(stack_ma, argc, argv);
}

long long	ft_atoll(char *str)
{
	long long	num;
	int			neg;

	neg = 1;
	num = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str != 0 && '0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
		if (num > INT_MAX && neg == 1)
			ft_exit("Error\n");
		if (num > INT_MIN && neg == -1)
			ft_exit("Error\n");
	}
	return (num * neg);
}

void	init_master(t_master *stack_m)
{
	stack_m->head = NULL;
	stack_m->tail = NULL;
	stack_m->size = 0;
}

void	push_data_stack_a(t_master *stack_ma, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
		push_element(stack_ma, ft_atoll(argv[i++]));
}

void	push_element(t_master *stack_ma, int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		ft_exit("Error\n");
	new->id = 0;
	new->value = num;
	(stack_ma->size)++;
	if (stack_ma->head == NULL)
	{
		stack_ma->head = new;
		stack_ma->tail = new;
		new->prev = NULL;
		new->next = NULL;
		return ;
	}
	stack_ma->tail->next = new;
	new->prev = stack_ma->tail;
	new->next = NULL;
	stack_ma->tail = new;
}
