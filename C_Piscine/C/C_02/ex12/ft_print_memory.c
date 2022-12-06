/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:45:26 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/21 09:52:55 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	Change2hexAddr(void *str)
{
	unsigned long long int	addr;
	int						i;
	char					output[20];

	addr = (unsigned long long int) str;
	i = 0;
	while (addr / 16 > 0)
	{
		if (addr % 16 > 9)
			output[i] = 'a' + addr % 16 - 10;
		else
			output[i] = addr % 16 + '0';
		i++;
		addr /= 16;
	}
	if (addr > 9)
		output[i] = 'a' + addr - 10;
	else
		output[i] = addr + '0';
	while (i < 16)
		output[i++] = '0';
	while (i >= 0)
		write(1, &output[i--], 1);
	write(1, ": ", 2);
}

void	Change2hexChar(char *str, int index)
{
	int		i;
	int		hexArr[2];
	char	output;

	i = 0;
	hexArr[0] = *str / 16;
	hexArr[1] = *str % 16;
	while (i < 2)
	{
		if (hexArr[i] > 9)
		{
			output = 'a' + hexArr[i] - 10;
			write(1, &output, 1);
		}
		else
		{
			output = hexArr[i] + '0';
			write(1, &output, 1);
		}
		i++;
	}
	if (index % 2)
		write(1, " ", 1);
}

void	Printf16Words(char *str)
{
	int	i;

	i = 0;
	while (i < 16 && str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	Print_lesWords(int les_words)
{
	int	j;

	j = 0;
	while (j < les_words)
	{
		write(1, " ", 1);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	les_words;
	char			*char_p;

	char_p = addr;
	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
			Change2hexAddr(&char_p[i]);
		Change2hexChar(&char_p[i], i);
		if (i % 16 == 15)
			Printf16Words(&char_p[(i / 16)*16]);
		if (i % 16 == 15)
			write(1, "\n", 1);
		i++;
	}
	les_words = 40 - (size % 16 * 2) - (size % 16 / 2);
	if (i % 16 != 0)
	{
		Print_lesWords(les_words);
		Printf16Words(&char_p[(size / 16)*16]);
		write(1, "\n", 1);
	}
	return (addr);
}

/* #include <stdio.h>
 int main()
{
	char str[100] = "SRYOU . ~<-9 starts here! I. am./ king?~\n\n\t\"\\happy\\\"";
	
	printf("----ex12----\n");
	printf("%s\n  %p\n",str, str);
	ft_print_memory(str,55);
	ft_print_memory(str,0);
	ft_print_memory(str+9,13);
	ft_print_memory("asdgasdgsdg",9);
} */
