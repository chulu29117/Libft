#include <stdio.h>

void    ft_ft(int *nbr)
{
         *nbr = 42;
}

int	main(void)
{
	int	r;
	r = 10;
	printf("%d\n", r);
	ft_ft(&r);
	printf("%d", r);
	return (0);
}
