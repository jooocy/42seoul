/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkang2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:31:16 by jkang2            #+#    #+#             */
/*   Updated: 2022/02/05 16:38:41 by jkang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern	void	ft_putchar(char c);

void	print__first__x(int y, int y_now)
{
	if (y_now == 1)
		ft_putchar('A');
	else if (y_now == y)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	print__last__x(int y, int y_now)
{
	if (y_now == 1)
		ft_putchar('A');
	else if (y_now == y)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	print__others(int y, int y_now)
{
	if (y_now != 1 && y_now != y)
		ft_putchar(' ');
	else
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int	x_now;
	int	y_now;

	y_now = 1;
	while (y_now <= y && x > 0)
	{
		x_now = 1;
		while (x_now <= x)
		{
			if (x_now == 1)
				print__first__x(y, y_now);
			else if (x_now == x)
				print__last__x(y, y_now);
			else
				print__others(y, y_now);
			x_now++;
		}
		ft_putchar('\n');
		y_now++;
	}
}
