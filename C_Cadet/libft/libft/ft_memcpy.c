/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:51:38 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/08 14:47:09 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t		i;
	char		*str;
	const char	*c_src;

	i = 0;
	str = dest;
	c_src = src;
	if (!src || !dest)
		return (dest);
	while (i < count)
	{
		str[i] = c_src[i];
		i++;
	}
	return (dest);
}
