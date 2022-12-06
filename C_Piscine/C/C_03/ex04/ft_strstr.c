/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:38:09 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/15 09:38:09 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_str(char *str, char *to_find, int find_index)
{
	int	i;

	i = 0;
	while (i < find_index)
	{
		if (str[i] != to_find[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	result;
	int	find_index;

	i = 0;
	find_index = 0;
	while (to_find[find_index])
		find_index++;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			result = check_str(&str[i], to_find, find_index);
			if (result == 1)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
