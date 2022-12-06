#include "libft.h"
#include <stdio.h>

int main()
{
	char *str = " abc";
	char **p;

	p = ft_split(str, ' ');
	printf("%s", p[0]);
}
