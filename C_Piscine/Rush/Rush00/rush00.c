/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:02:44 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/05 16:50:17 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern	void	ft_putchar(char c);

void	print__first__x(int y, int y_now)
{
	if (y_now == 1)
		ft_putchar('o');
	else if (y_now == y)
		ft_putchar('o');
	else
		ft_putchar('|');
}

void	print__last__x(int y, int y_now)
{
	if (y_now == 1)
		ft_putchar('o');
	else if (y_now == y)
		ft_putchar('o');
	else
		ft_putchar('|');
}

void	print__others(int y, int y_now)
{
	if (y_now != 1 && y_now != y)
		ft_putchar(' ');
	else
		ft_putchar('-');
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
