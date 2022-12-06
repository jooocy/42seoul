/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:17:56 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/17 12:37:41 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_non(char *str)
{
	int				i;
	int				hexArr[2];
	unsigned char	output;

	i = 0;
	hexArr[0] = (unsigned char)*str / 16;
	hexArr[1] = (unsigned char)*str % 16;
	write(1, "\\", 1);
	while (i < 2)
	{
		if (hexArr[i] > 9)
		{
			output = 'a' + hexArr[i] - 10;
			write(1, &output, 1);
		}
		else
		{
			output = hexArr[i] + '0';
			write(1, &output, 1);
		}
		i++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
			print_non(&str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
