/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:56:31 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/05 14:01:52 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(const char *str, int *i)
{
	int	signal;

	signal = 1;
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v' || \
	str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			signal = -signal;
		(*i)++;
	}
	return (signal);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	result;

	i = 0;
	result = 0;
	signal = check(str, &i);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			if (signal == 1)
				result += str[i] - '0';
			else
				result -= str[i] - '0';
		}
		else
			break ;
		i++;
	}
	return (result);
}
