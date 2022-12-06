/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:58:52 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/08 14:54:09 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int to_find)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i <= len)
	{
		if (str[i] == (const char)to_find)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
