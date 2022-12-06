/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_any_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:06:29 by jojoo             #+#    #+#             */
/*   Updated: 2022/11/08 05:17:16 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_any_sort(t_master *stack_ma, t_master *stack_mb)
{
	make_clock_hours(stack_ma, stack_mb);
	sort_b_to_a(stack_ma, stack_mb);
}

void	make_clock_hours(t_master *stack_ma, t_master *stack_mb)
{
	int		chunk;
	int		num;

	num = 0;
	chunk = 0.000000053 * stack_ma->size * stack_ma->size \
	+ 0.03 * stack_ma->size + 14.5;
	while (stack_ma->size)
	{
		if (stack_ma->head->id <= num)
		{
			operation(stack_ma, stack_mb, PB);
			num++;
		}
		else if (stack_ma->head->id <= num + chunk)
		{
			operation(stack_ma, stack_mb, PB);
			operation(stack_ma, stack_mb, RB);
			num++;
		}
		else if (stack_ma->tail->id <= num + chunk)
			operation(stack_ma, stack_mb, RRA);
		else
			operation(stack_ma, stack_mb, RA);
	}
}

void	sort_b_to_a(t_master *stack_ma, t_master *stack_mb)
{
	int	target;

	target = stack_mb->size - 1;
	while (stack_mb->size > 0)
	{
		if (stack_mb->head->id == target)
		{
			operation(stack_ma, stack_mb, PA);
			target--;
		}
		else
		{
			if (is_target_in_top_exactly(stack_mb, target) < \
				is_target_in_down_exactly(stack_mb, target))
				rotate_stack_exactly(stack_mb, target, RB);
			else
				rotate_stack_exactly(stack_mb, target, RRB);
		}
	}
}
