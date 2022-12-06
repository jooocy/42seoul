/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:42:51 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/25 21:25:45 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_strlen(char *s1, char token)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] != token)
		i++;
	return (i);
}

int	my_strchr(const char *str, int to_find)
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

char	*ft_split_join(char *s1, char *s2, t_list *temp)
{
	int		size1;
	int		size2;
	int		i;
	char	*result;

	size1 = my_strlen(s1, '\0');
	size2 = my_strlen(s2, '\n');
	i = my_strlen(s2, '\0');
	temp->content = malloc(sizeof(char) * (i - size2));
	result = malloc(sizeof(char) * (size1 + ++size2 + 1));
	if (!result && !(temp->content))
		return (0);
	i = -1;
	while (++i < size1)
		result[i] = s1[i];
	i = 0;
	while (i < size2)
		result[size1++] = s2[i++];
	result[size1] = '\0';
	size1 = 0;
	while (s2[i])
		temp->content[size1++] = s2[i++];
	temp->content[size1] = '\0';
	free(s1);
	return (result);
}

char	*my_strjoin(char *s1, char *s2, int num)
{
	int		size1;
	int		i;
	char	*result;

	i = -1;
	size1 = my_strlen(s1, '\0');
	result = malloc((sizeof(char) * (size1 + my_strlen(s2, '\0')) + 1));
	if (!result)
		return (0);
	while (++i < size1)
		result[i] = s1[i];
	i = 0;
	while (i < my_strlen(s2, '\0'))
		result[size1++] = s2[i++];
	result[size1] = '\0';
	free(s1);
	if (num)
		free(s2);
	if (num == 2 && size1 == 0)
	{
		free(result);
		return (0);
	}
	return (result);
}
