#include <unistd.h>

void	ft_putchar(char c);
void	print_num(int num);
void map_num(int map[4][4]);

int	map(char c)
{
	c = 1;
	int	map[4][4];
	int	row;
	int	col;
	
	map_num(map);
		
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			print_num(map[row][col]);
			
			if (col < 4 - 1)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	row = 0;
	return (0);	
}
