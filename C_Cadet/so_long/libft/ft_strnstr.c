/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:58:34 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/05 15:06:55 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_str(const char *str, const char *to_find, size_t find_index)
{
	size_t	i;

	i = 0;
	while (i < find_index)
	{
		if (str[i] != to_find[i])
			return (0);
		i++;
	}
	return (1);
}

size_t	my_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	find_index;
	size_t	str_index;
	int		result;

	i = 0;
	find_index = my_strlen(to_find);
	str_index = my_strlen(str);
	if (!find_index)
		return ((char *)str);
	while (i < n && i <= str_index)
	{
		if ((n - i) < find_index)
			break ;
		if (str[i] == to_find[0])
		{
			result = check_str(&str[i], to_find, find_index);
			if (result == 1)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
