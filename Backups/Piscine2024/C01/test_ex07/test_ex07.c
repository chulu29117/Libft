#include <stdio.h>

void    ft_rev_int_tab(int *tab, int size)
{
	int i;
	int temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;  
	}
}

int	main(void)
{
	int tab[] = {1, 2, 3, 4, 5};
	int size;
	int i;

	size = 5;
	i = 0;
	while (tab[i] != '\0')
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	ft_rev_int_tab(tab, size);
	i = 0;
	while (tab[i] != '\0')
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}
