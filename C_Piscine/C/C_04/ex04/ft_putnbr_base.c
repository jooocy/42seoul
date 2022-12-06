/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:26:02 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/20 15:36:22 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_base_error(char *base, int index)
	{
	int	i;
	int	j;

	i = 0;
	if (index < 2)
		return (1);
	while (base[i])
	{
		j = 0;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (j < i)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*change_dec2base(int nbr, int base_index)
{
	static int	arrint[100];
	int			i;

	i = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
		{
			arrint[i] = (nbr % base_index) * -1;
			nbr /= base_index;
			i++;
		}
		nbr = -nbr;
	}
	while (nbr / base_index > 0)
	{
		arrint[i] = nbr % base_index;
		nbr /= base_index;
		i++;
	}
	arrint[i++] = nbr;
	arrint[i] = -1;
	return (arrint);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_index;
	int		i;
	int		*nbr2base;
	char	base2char[100];
	int		signal;

	base_index = 0;
	signal = 0;
	while (base[base_index])
		base_index++;
	if (check_base_error(base, base_index) == 1)
		return ;
	nbr2base = change_dec2base(nbr, base_index);
	i = 0;
	while (nbr2base[i] != -1)
	{
		base2char[i] = base[nbr2base[i]];
		i++;
	}
	i--;
	while (i >= 0)
		write(1, &base2char[i--], 1);
}
