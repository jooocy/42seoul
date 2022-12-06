/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:58:00 by jojoo             #+#    #+#             */
/*   Updated: 2022/11/11 22:19:27 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	size_three_sort(t_master *stack_ma)
{
	int	s1;
	int	s2;
	int	s3;

	if (is_sorted(stack_ma))
		return ;
	s1 = stack_ma->head->id;
	s2 = stack_ma->head->next->id;
	s3 = stack_ma->head->next->next->id;
	if (s1 < s2 && s1 < s3)
	{
		operation(stack_ma, NULL, SA);
		operation(stack_ma, NULL, RA);
	}
	else if (s1 > s2 && s1 < s3 && s2 < s3)
		operation(stack_ma, NULL, SA);
	else if (s1 < s2 && s1 > s3 && s2 > s3)
		operation(stack_ma, NULL, RRA);
	else
	{
		operation(stack_ma, NULL, RA);
		if (s2 > s3)
			operation(stack_ma, NULL, SA);
	}
}

void	size_four_sort(t_master *stack_ma, t_master *stack_mb)
{
	while (stack_ma->size > 3)
	{
		if (stack_ma->head->id == 0)
		{
			operation(stack_ma, stack_mb, PB);
			break ;
		}
		else
			operation(stack_ma, stack_mb, RA);
	}
	size_three_sort(stack_ma);
	operation(stack_ma, stack_mb, PA);
}

void	size_five_sort(t_master *stack_ma, t_master *stack_mb)
{
	while (stack_ma->size > 3)
	{
		if (stack_ma->head->id < 2)
			operation(stack_ma, stack_mb, PB);
		else
			operation(stack_ma, stack_mb, RA);
	}
	size_three_sort(stack_ma);
	operation(stack_ma, stack_mb, PA);
	operation(stack_ma, stack_mb, PA);
	if (stack_ma->head->id != 0)
		operation(stack_ma, stack_mb, SA);
}

void	do_algorithm(t_master *stack_ma, t_master *stack_mb)
{
	if (stack_ma->size == 2)
		operation(stack_ma, stack_mb, SA);
	else if (stack_ma->size == 3)
		size_three_sort(stack_ma);
	else if (stack_ma->size == 4)
		size_four_sort(stack_ma, stack_mb);
	else if (stack_ma->size == 5)
		size_five_sort(stack_ma, stack_mb);
	else
		size_any_sort(stack_ma, stack_mb);
}
