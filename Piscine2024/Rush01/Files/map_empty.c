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
		ft_putchar(buffer[i]);
		i--;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// Function printing the 4x4 array with malloc()

int	map(void)
{
	int	**map;
	int	row;
	int	col;
	int	size;
	
	size = 4;
	row = 0;
	map = (int **) malloc(size * sizeof(int *));
	while (row < size)
	{
		map[row] = (int *)malloc(size * sizeof(int));
		row++;
	}	
	
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			map[row][col] = 0;
			col++;
		}
		row++;
	}
	
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			print_num(map[row][col]);
			
			if (col < size - 1)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	row = 0;
	while (row < size)
	{
		free(map[row]);
		row++;
	}
	free(map);
	return (0);	
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int	main(void)
{
	map();
	return (0);
}




