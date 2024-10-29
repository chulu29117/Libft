/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:55:54 by clu               #+#    #+#             */
/*   Updated: 2024/09/14 13:03:51 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// Function to print positive integer number

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

/////////////////////////////////////////////////////////////////////////////////////////////////
// Function to initialize the grid with hardcoded numbers
void input_grid(int map[4][4])
{
	int 	num[4][4] = {
		{1, 2, 3, 4},
		{2, 3, 4, 1},
		{3, 4, 1, 2},
		{4, 1, 2, 3}
	};
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			map[row][col] = num[row][col];
			col++;
		}
		row++;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int	map(char c)
{
	c = 1;
	int	map[4][4];
	int	row;
	int	col;
	
	input_grid(map);
		
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


/////////////////////////////////////////////////////////////////////////////////////////////////

int	main(int argc, char *argv[])
{
	if (argc == 2)
		map(*argv[1]);
	else
		write(1, &"Invalid input, correct input is: \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"\n", 70);  
	return (0);
}




