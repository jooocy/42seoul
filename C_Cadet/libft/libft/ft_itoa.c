/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:53:00 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/08 14:42:48 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	int2char(char *tmp, int n)
{
	int	i;

	i = 0;
	while (n / 10)
	{
		if (n < 0)
			tmp[i++] = ((n % 10) * (-1)) + '0';
		else
			tmp[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (n < 0)
	{
		tmp[i++] = -n + '0';
		tmp[i] = '-';
	}
	else
		tmp[i] = n + '0';
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		j;
	char	tmp[100];

	j = 0;
	i = int2char(tmp, n);
	result = (char *)malloc(sizeof(char) * i + 2);
	if (!result)
		return (0);
	while (i >= 0)
		result[j++] = tmp[i--];
	result[j] = '\0';
	return (result);
}
