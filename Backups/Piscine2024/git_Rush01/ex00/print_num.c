#include <unistd.h>

void	ft_putchar(char c);

void	print_num(int num)
{
	char buffer[10];
	int	i = 0;
	
	if (num == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (num > 0)
	{
		buffer[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	while (i >= 0)
	{	
		i--;
		ft_putchar(buffer[i]);
	}
}
