/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:50:31 by jojoo             #+#    #+#             */
/*   Updated: 2022/07/06 16:17:07 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void ft_put_dec(unsigned int n)
{
	int tmp[100];
	int i;

	i = 0;
	if (n >= 10)
	{
		while (n >= 10)
		{
			tmp[i++] = n % 10;
			n /= 10;
		}
		tmp[i] = n;
		while (i >= 0)
			ft_print_char('0' + tmp[i--]);
	}
	else
		ft_print_char('0' + n);
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (!n)
		len += write(1, "0", 1);
	else
	{
		ft_put_dec(n);
		len += ft_dec_len(n);
	}
	return (len);
}
