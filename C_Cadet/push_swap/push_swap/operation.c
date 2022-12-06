/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:42:44 by jojoo             #+#    #+#             */
/*   Updated: 2022/11/11 23:29:40 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	operation(t_master *stack_ma, t_master *stack_mb, int command)
{
	printf_command(command);
	if (command == SA)
		ft_swap(stack_ma);
	if (command == SB)
		ft_swap(stack_mb);
	if (command == PA)
		ft_push(stack_ma, stack_mb);
	if (command == PB)
		ft_push(stack_mb, stack_ma);
	if (command == RA)
		ft_rotate(stack_ma);
	if (command == RB)
		ft_rotate(stack_mb);
	if (command == RRA)
		ft_rrotate(stack_ma);
	if (command == RRB)
		ft_rrotate(stack_mb);
}

void	ft_swap(t_master *stack_m)
{
	t_node	*stack;
	int		tmp_value;
	int		tmp_id;

	if (stack_m->size < 2)
		return ;
	stack = stack_m->head;
	tmp_id = stack->id;
	tmp_value = stack->value;
	stack->id = stack->next->id;
	stack->value = stack->next->value;
	stack->next->id = tmp_id;
	stack->next->value = tmp_value;
}

void	ft_push(t_master *to, t_master *from)
{
	t_node	*tmp;

	if (from->size < 1)
		return ;
	if (to->size < 1)
		ft_push_two(to, from);
	else
	{
		to->size++;
		from->size--;
		tmp = to->head;
		tmp->prev = from->head;
		to->head = from->head;
		from->head = from->head->next;
		if (from->head)
			from->head->prev = NULL;
		tmp->prev->next = tmp;
		if (from->size == 0)
			from->tail = NULL;
	}
}

void	ft_push_two(t_master *to, t_master *from)
{
	to->head = from->head;
	to->tail = from->head;
	from->head = from->head->next;
	from->head->prev = NULL;
	to->head->next = NULL;
	if (from->size == 1)
		from->tail = NULL;
	to->size++;
	from->size--;
}

void	ft_rotate(t_master *stack_m)
{
	t_node	*tmp;

	if (stack_m->size < 2)
		return ;
	tmp = stack_m->head;
	tmp->next->prev = NULL;
	stack_m->head = tmp->next;
	tmp->prev = stack_m->tail;
	stack_m->tail->next = tmp;
	tmp->next = NULL;
	stack_m->tail = tmp;
}
