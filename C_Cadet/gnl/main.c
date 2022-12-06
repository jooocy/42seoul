/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:31:01 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/16 18:55:00 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int	fd;
	char *p;
	fd = open("test.txt", O_RDONLY);
	// printf("fd: %d\n", fd);
	while (1)
	{
		p = get_next_line(fd);
		printf("%s", p);
		if(!p)
			return 0;
		}
}
