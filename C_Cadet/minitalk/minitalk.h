/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:48:25 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/01 11:42:18 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

struct sigaction	g_server_act;
struct sigaction	g_client_act;

typedef struct s_data
{
	pid_t			pid;
	char			*contents;
}			t_data;

#endif