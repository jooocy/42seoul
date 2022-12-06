/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:41:24 by jojoo             #+#    #+#             */
/*   Updated: 2022/07/06 16:17:22 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printformat(const char f, va_list vl)
{
	int		len;

	len = 0;
	if (f == 'c')
		len += ft_print_char(va_arg(vl, int));
	else if (f == 's')
		len += ft_print_str(va_arg(vl, char *));
	else if (f == 'p')
		len += ft_print_ptr(va_arg(vl, uintptr_t));
	else if (f == 'd' || f == 'i')
		len += ft_print_dec(va_arg(vl, int));
	else if (f == 'u')
		len += ft_print_unsigned(va_arg(vl, unsigned int));
	else if (f == 'x' || f == 'X')
		len += ft_print_hex(f, va_arg(vl, unsigned int));
	else if (f == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	vl;

	len = 0;
	i = 0;
	va_start(vl, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_printformat(str[++i], vl);
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(vl);
	return (len);
}
