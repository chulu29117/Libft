/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:50:59 by clu               #+#    #+#             */
/*   Updated: 2024/09/08 11:20:35 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include    <unistd.h>

void	ft_putchar(char c);

void	ft_print_table(int row, int col, int x, int y)
{
	if (((row == 1 && col == 1) || (row == 1 && col == x))
		|| (row == y && col == 1) || (row == y && col == x))
		ft_putchar('o');
	else if (row == 1 || row == y)
		ft_putchar('-');
	else if (col == 1 || col == x)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	if (x <= 0 || y <= 0)
	{
		write (1, "invalid input, use int numbers > 0", 34);
		return ;
	}
	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			ft_print_table (row, col, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
