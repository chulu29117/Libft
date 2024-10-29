/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:41:39 by clu               #+#    #+#             */
/*   Updated: 2024/09/13 11:17:00 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	res = 1;
	while (nb > 1)
	{
		res = res * nb;
		nb--;
	}
	return (res);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int	nb = atoi(argv[1]);

		printf("Factorial number of %d: %d\n", nb, ft_iterative_factorial(nb));
	}
	else
	{
		printf("1 input required");
	}
	return (0);
}
