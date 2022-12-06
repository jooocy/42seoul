/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:58:26 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/08 14:56:39 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	s_len;
	size_t			i;

	i = 0;
	if (!s)
		return (0);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	s_len = ft_strlen((char *)s);
	if (s_len > start)
	{
		while (i < len)
			result[i++] = s[start++];
	}
	result[i] = '\0';
	return (result);
}
