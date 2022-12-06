/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@42SEOUL.KR>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:37:01 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/14 16:38:44 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *a1, char *a2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (a1[i] != a2[i])
			return (a1[i] - a2[i]);
		if (a1[i] == '\0' && a2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
