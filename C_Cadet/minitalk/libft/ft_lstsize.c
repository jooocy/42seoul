/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:31:34 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/05 13:55:00 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		result;
	t_list	*temp;

	result = 0;
	temp = lst;
	while (temp)
	{
		result++;
		temp = temp->next;
	}
	return (result);
}
