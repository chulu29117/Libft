/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:03:36 by riamaev           #+#    #+#             */
/*   Updated: 2024/09/08 10:47:17 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_tabl(int col, int row, int x, int y)
{
	if ((row == 1 && col == 1) || (row == y && col == 1))
		ft_putchar('A');
	else if ((row == 1 && col == x) || (row == y && col == x))
		ft_putchar('C');
	else if ((col > 1 && col < x) && (row > 1 && row < y))
		ft_putchar(' ');
	else
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	if (x < 1 || y < 1)
	{
		write(1, "invalid input, use int numbers > 0", 34);
		return ;
	}
	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			ft_print_tabl(col, row, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
