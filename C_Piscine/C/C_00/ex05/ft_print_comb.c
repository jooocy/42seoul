/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@42SEOUL.KR>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:49:28 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/08 14:49:29 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(char arr[])
{
	write(1, &arr[0], 1);
	write(1, &arr[1], 1);
	write(1, &arr[2], 1);
}

void	ft_print_comb(void)
{
	char	arr[3];

	arr[0] = '0';
	arr[1] = '1';
	arr[2] = '2';
	while (arr[0] != '7')
	{
		print_numbers(arr);
		write(1, ", ", 2);
		arr[2]++;
		if (arr[2] > '9')
		{
			arr[1]++;
			if (arr[1] > '8')
			{
				arr[0]++;
				arr[1] = arr[0] + 1;
			}
			arr[2] = arr[1] + 1;
		}
	}
	print_numbers(arr);
}
