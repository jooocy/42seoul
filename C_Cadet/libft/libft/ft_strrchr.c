/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:58:30 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/05 15:32:47 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (0 <= i)
	{
		if (str[i] == (char)to_find)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
