/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:26:07 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/17 21:26:14 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	mv_numbers(char arr[], int index, int nb)
{
	while (nb / 10 != 0)
	{
		arr[index++] = (nb % 10) + '0';
		nb /= 10;
	}
	arr[index] = nb + '0';
	return (index);
}

void	ft_putnbr(int nb)
{
	char	arr[10];
	int		index;

	index = 0;
	if (nb >= 0)
		index = mv_numbers(arr, index, nb);
	else
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			index = -1;
		}
		else
		{
			index = mv_numbers(arr, index, -nb);
			write(1, "-", 1);
		}
	}
	while (index >= 0)
		write(1, &arr[index--], 1);
}
