/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:58:28 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/08 14:56:35 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		front;
	int		end;

	result = 0;
	if (s1 && set)
	{
		front = 0;
		end = ft_strlen((char *)s1);
		while (ft_strchr((char *)set, s1[front]) && front < end)
			front++;
		while (ft_strchr((char *)set, s1[end - 1]) && front < end)
			end--;
		result = (char *)malloc(sizeof(char) * (end - front + 1));
		if (result)
			ft_strlcpy(result, (char *)&s1[front], end - front + 1);
	}
	return (result);
}
