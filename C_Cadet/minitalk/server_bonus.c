/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:48:16 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/01 13:16:10 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minitalk.h"

t_data	g_server_data;

void	handle_action(int signum)
{
	static int	bit = 8;
	static char	ch = 0;

	if (signum == SIGUSR1)
		ch += 1 << --bit;
	else if (signum == SIGUSR2)
		bit--;
	if (bit == 0)
	{
		write(1, &ch, 1);
		bit = 8;
		ch = 0;
	}
}

int	main(void)
{
	char	*pid;

	write(1, "server pid: ", 12);
	pid = ft_itoa(getpid());
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	g_server_act.sa_flags = SA_SIGINFO;
	g_server_act.__sigaction_u.__sa_sigaction = (void *)handle_action;
	sigaction(SIGUSR1, &g_server_act, NULL);
	sigaction(SIGUSR2, &g_server_act, NULL);
	while (1)
		pause();
	return (0);
}
