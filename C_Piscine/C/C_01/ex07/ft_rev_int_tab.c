/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@42SEOUL.KR>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:24:52 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/08 20:26:37 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	recur(int *tab, int count, int size)
{
	int	i;
	int	j;
	int	temp;

	i = count;
	while (i < size - 1)
	{
		temp = tab[count];
		j = count;
		while (j < size - 1)
		{
			tab[j] = tab[j + 1];
			j++;
		}
		tab[size - 1] = temp;
		i++;
	}
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		recur(tab, i, size);
		i++;
	}
}
