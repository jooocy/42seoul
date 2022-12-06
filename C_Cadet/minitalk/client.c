/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:24:11 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/01 11:42:32 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minitalk.h"

t_data	g_client_data;

void	handle_char2bit(char ch)
{
	static int	bit = 8;

	while (bit != 0)
	{
		usleep(500);
		if ((ch >> --bit) & 1)
			kill(g_client_data.pid, SIGUSR1);
		else
			kill(g_client_data.pid, SIGUSR2);
	}
	bit = 8;
}

void	send_message(void)
{
	int	i;

	i = 0;
	while (g_client_data.contents[i])
		handle_char2bit(g_client_data.contents[i++]);
}

int	is_error_pid(char *pid)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(pid);
	while (i < len)
	{
		if (!ft_isdigit(pid[i++]))
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	if (is_error_pid(av[1]))
		return (0);
	g_client_data.pid = ft_atoi(av[1]);
	g_client_data.contents = av[2];
	send_message();
	return (0);
}
