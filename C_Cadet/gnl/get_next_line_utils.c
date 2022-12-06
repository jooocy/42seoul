/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:42:51 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/16 20:39:03 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s1, char token)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] != token)
		i++;
	return (i);
}

int	ft_strchr(const char *str, int to_find)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	while (i <= len)
	{
		if (str[i] == (const char)to_find)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(t_list **lst_buff, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*result;

	i = -1;
	s1_len = ft_strlen((*lst_buff)->content, '\0');
	s2_len = ft_strlen(s2, '\0');
	result = malloc((sizeof(char) * (s1_len + s2_len - 1)));
	if (!result)
	{
		free(s2);
		s2 = NULL;
		return (0);
	}
	while (++i < s1_len)
		result[i] = (*lst_buff)->content[i];
	i = 0;
	while (i < s2_len)
		result[s1_len++] = s2[i++];
	result[s1_len] = '\0';
	if (!(*lst_buff)->content)
		free((*lst_buff)->content);
	(*lst_buff)->content = NULL;
	return (result);
}
