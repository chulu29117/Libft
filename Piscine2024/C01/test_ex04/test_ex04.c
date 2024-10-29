#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

int	main(void)
{
	int a;
	int b;

	a = 20;
	b = 10;
	
	if (b == 0)
		printf("Invalid input, b != 0");
	else
	{
		printf("a = %d, b = %d\n", a, b);
		ft_ultimate_div_mod(&a, &b);
		printf("Div ab = %d, Mod ab = %d\n", a, b);
	}
}
