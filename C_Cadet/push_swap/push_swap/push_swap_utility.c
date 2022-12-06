/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:57:21 by jojoo             #+#    #+#             */
/*   Updated: 2022/11/08 05:45:46 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	is_target_in_top_exactly(t_master *stack_ma, int target)
{
	t_node	*stack;
	int		index;
	int		half_size;

	stack = stack_ma->head;
	half_size = stack_ma->size / 2;
	index = 0;
	while (stack && index <= half_size)
	{
		if (stack->id == target)
			return (index - 1);
		index++;
		stack = stack->next;
	}
	return (index - 1);
}

int	is_target_in_down_exactly(t_master *stack_ma, int target)
{
	t_node	*stack;
	int		index;
	int		half_size;

	stack = stack_ma->tail;
	half_size = stack_ma->size / 2;
	index = 0;
	while (stack && index < half_size)
	{
		if (stack->id == target)
			return (index);
		index++;
		stack = stack->prev;
	}
	return (index);
}

void	rotate_stack_exactly(t_master *stack_m, int target, int command)
{
	while (stack_m->head->id != target)
		operation(stack_m, stack_m, command);
}

void	printf_command(int command)
{
	if (command == SA)
		write(1, "sa\n", 3);
	if (command == SB)
		write(1, "sb\n", 3);
	if (command == PA)
		write(1, "pa\n", 3);
	if (command == PB)
		write(1, "pb\n", 3);
	if (command == RA)
		write(1, "ra\n", 3);
	if (command == RB)
		write(1, "rb\n", 3);
	if (command == RRA)
		write(1, "rra\n", 4);
	if (command == RRB)
		write(1, "rrb\n", 4);
}

void	ft_rrotate(t_master *stack_m)
{
	t_node	*tmp;

	if (stack_m->size < 2)
		return ;
	tmp = stack_m->tail;
	stack_m->tail = tmp->prev;
	tmp->next = stack_m->head;
	stack_m->head->prev = tmp;
	stack_m->head = tmp;
	tmp->prev = NULL;
	stack_m->tail->next = NULL;
}
