/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo42SEOUL.KR>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:39:01 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/13 16:39:04 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	get_col_row(char *str);

int	g_error;

int	check_pre(char cur, char pre)
{
	if (pre > '0' && pre <= '4')
	{
		if (cur != ' ')
			return (0);
	}
	else if (pre == ' ')
	{
		if (cur <= '0' || cur > '4')
			return (0);
	}
	else
		return (0);
	return (1);
}

int	check_input(char *str)
{
	char	*ret;
	int		count;

	ret = str;
	count = 0;
	if (*str > '0' && *str <= '4')
		count++;
	else
		return (1);
	str++;
	while (*str != '\0')
	{
		if (check_pre(*str, *(str - 1)) == 0)
			return (1);
		if (*str != ' ')
			count++;
		if (count == 16 && *(str + 1) != '\0')
			return (1);
		str++;
	}
	if (count != 16)
		return (1);
	get_col_row(ret);
	return (g_error);
}

int	main(int argc, char *argv[])
{
	g_error = 0;
	if (argc == 2)
		g_error = check_input(argv[1]);
	else
		g_error = 1;
	if (g_error == 1)
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
