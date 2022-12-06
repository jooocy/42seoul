/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:58:56 by jojoo             #+#    #+#             */
/*   Updated: 2022/04/08 14:53:31 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	split_sentence(const char *s, char c)
{
	int	i;
	int	words_num;

	i = 0;
	words_num = 0;
	while (s[i])
	{
		if (!s[i + 1])
		{
			if (s[i] != c)
				words_num++;
			break ;
		}
		if ((s[i] != c) && (s[i + 1] == c))
			words_num++;
		i++;
	}
	return (words_num);
}

int	set_words(const char *s, int w, char ****result, int j)
{
	(**result)[j] = (char *)malloc(sizeof(char) * (w));
	if (!((**result)[j]))
		return (0);
	ft_strlcpy((**result)[j], (char *)s, w);
	return (1);
}

int	count_words(const char *s, char c, char ***result)
{
	int	w;
	int	i;
	int	j;

	w = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{	
			w++;
			if ((s[i + 1] == c) || !s[i + 1])
			{
				if (!set_words(&s[i - w + 1], (w + 1), &result, j++))
					return (j);
				w = 0;
			}
		}
		i++;
	}
	(*result)[j] = NULL;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words_num;
	int		i;
	int		j;

	if (!s)
		return (0);
	words_num = split_sentence(s, c);
	result = 0;
	result = (char **)malloc(sizeof(char *) * (words_num + 1));
	if (!result)
		return (0);
	j = count_words(s, c, &result);
	if (j >= 0)
	{
		i = 0;
		while (i < j)
			free(result[i++]);
		free(result);
		result = 0;
	}
	return (result);
}
