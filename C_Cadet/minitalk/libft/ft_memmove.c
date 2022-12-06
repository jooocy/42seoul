/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:50:27 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/08 14:48:08 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t		i;
	char		*str;
	const char	*c_src;

	i = -1;
	str = dest;
	c_src = src;
	if (!src && !dest)
		return (dest);
	if (dest < src)
	{
		while (++i < count)
			str[i] = c_src[i];
	}
	else
	{
		while (++i < count)
			str[count - i - 1] = c_src[count - i - 1];
	}
	return (dest);
}
