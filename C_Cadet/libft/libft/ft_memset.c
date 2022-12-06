/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:49:34 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/08 13:22:16 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = dest;
	while (i < count)
	{
		str[i] = (unsigned char)ch;
		i++;
	}
	return (dest);
}
