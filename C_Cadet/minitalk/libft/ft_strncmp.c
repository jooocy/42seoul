/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:58:35 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/05 14:45:46 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *a1, const char *a2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)a1[i] != (unsigned char)a2[i])
			return ((unsigned char)a1[i] - (unsigned char)a2[i]);
		if (a1[i] == '\0' && a2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
