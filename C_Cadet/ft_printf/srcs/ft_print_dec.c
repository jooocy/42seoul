/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:51:55 by jojoo             #+#    #+#             */
/*   Updated: 2022/07/06 16:16:15 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec(int d)
{
	int		len;
	char	*nptr;

	len = 0;
	nptr = ft_itoa(d);
	free(nptr);
	len = ft_print_str(nptr);
	return (len);
}
