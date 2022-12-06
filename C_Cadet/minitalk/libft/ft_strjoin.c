/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:58:44 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/08 14:55:18 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
	{
		result = (char *)malloc(1);
		if (!result)
			return (0);
		*result = '\0';
		return (result);
	}
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (0);
	ft_memmove(result, s1, s1_len);
	ft_memmove(&result[s1_len], s2, s2_len + 1);
	return (result);
}
