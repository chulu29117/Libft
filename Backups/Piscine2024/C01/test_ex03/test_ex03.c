#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)'\0'
	{
		*div = a / b;
		*mod = a % b;
	}
}

int	main(void)
{
	int	a;
	int	b;
	
	a = 20;
	b = 2;
	
	int	div;
	int	mod;
	
	if (b == 0)
		printf("Invalid input, b != 0");
	else
	{
		printf("a = %d, b = %d\n", a, b);
		ft_div_mod(a, b, &div, &mod);
		printf("Division: %d, Modulo: %d", div, mod);
		return (0);
	}
}
