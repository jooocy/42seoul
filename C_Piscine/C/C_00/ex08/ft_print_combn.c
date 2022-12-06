/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:41:59 by jojoo             #+#    #+#             */
/*   Updated: 2022/02/19 21:35:19 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	recur(int *arr, int index, int count)
{
	if (arr[0] == 9 - index)
		return (1);
	arr[index]++;
	if (arr[index] > count)
	{
		arr[index - 1]++;
		if (arr[index - 1] > count - 1)
		{
			recur(arr, index - 1, count - 1);
		}
		arr[index] = arr[index - 1] + 1;
	}
	return (0);
}

void	ft_print_combn(int n)
{
	int		numArr[10];
	int		i;
	char	output;

	i = 0;
	while (i < n)
	{
		numArr[i] = i;
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < n)
		{
			output = numArr[i] + '0';
			write(1, &output, 1);
			i++;
		}
		if (recur(numArr, n - 1, 9))
			break ;
		write(1, ", ", 2);
	}
}
/*      ㅊㅜㄹ력  
		 numArr[n]++;
         if(numArr[n] > 9)
         {
             numArr[n-1]++;
             if(numArr[n-1] > 9-1)
             {
                 numArr[n-2]++;
                 if(numArr[n-2] > 9-2)
                 {
                     numArr[n-3]++;
                     numArr[n-2] = numArr+1;
                 }
                 numArr[n-1] = numArr[n-2] +1;
             }
             numArr[n] = numArr[n-1] + 1;
         } */
