/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:56:23 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/08 12:46:41 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *dest, size_t count)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!dest)
		return (NULL);
	str = dest;
	while (i < count)
	{
		str[i] = 0;
		i++;
	}
	return (dest);
}
