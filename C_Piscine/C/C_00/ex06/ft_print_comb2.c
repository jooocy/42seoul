/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@42SEOUL.KR>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:49:44 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/09 09:56:16 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(char arr[])
{
	write(1, &arr[0], 1);
	write(1, &arr[1], 1);
	write(1, " ", 1);
	write(1, &arr[2], 1);
	write(1, &arr[3], 1);
}

void	avoid_norm_error(char arr[])
{
	if (arr[1] > '9')
	{
		arr[1] = '0';
		arr[0]++;
	}
	arr[2] = arr[0];
	arr[3] = arr[1] + 1;
	if (arr[3] > '9')
	{
		arr[3] = '0';
		arr[2]++;
	}
}

void	ft_print_comb2(void)
{
	char	arr[4];

	arr[0] = '0';
	arr[1] = '0';
	arr[2] = '0';
	arr[3] = '1';
	while (1)
	{
		print_numbers(arr);
		arr[3]++;
		if (arr[3] > '9')
		{
			arr[3] = '0';
			arr[2]++;
			if (arr[2] > '9')
			{
				arr[2] = '0';
				arr[1]++;
				if (arr[0] == '9' && arr[1] == '9')
					break ;
				avoid_norm_error(arr);
			}		
		}
		write(1, ", ", 2);
	}
}
int main()
{
	ft_print_comb2();
}
