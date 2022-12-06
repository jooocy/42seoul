/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:49:51 by jojoo             #+#    #+#             */
/*   Updated: 2022/07/06 16:16:25 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(uintptr_t n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_put_hex(const char f, uintptr_t n)
{
	if (n >= 16)
	{
		ft_put_hex(f, n / 16);
		ft_put_hex(f, n % 16);
	}
	else if (n <= 9)
		ft_print_char('0' + n);
	else
	{
		if (f == 'x')
			ft_print_char('a' + n - 10);
		else if (f == 'X')
			ft_print_char('A' + n - 10);
	}
}

int	ft_print_hex(const char f, unsigned int n)
{
	if (!n)
		return (write(1, "0", 1));
	else
		ft_put_hex(f, (uintptr_t)n);
	return (ft_hex_len((uintptr_t)n));
}
