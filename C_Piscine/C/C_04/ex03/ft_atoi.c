/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:25:57 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/20 15:11:02 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char *str, int *i)
{
	int	signal;

	signal = 1;
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v' || \
	str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{	
		if (str[*i] == '-')
			signal = -signal;
		(*i)++;
	}
	return (signal);
}

int	ft_atoi(char *str)
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
