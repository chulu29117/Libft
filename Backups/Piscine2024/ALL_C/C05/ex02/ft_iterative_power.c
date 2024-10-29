/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:47:29 by clu               #+#    #+#             */
/*   Updated: 2024/09/13 12:08:34 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0 )
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		res = nb * res;
		power--;
	}
	return (res);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
	int	nb = atoi(argv[1]);
	int	power = atoi(argv[2]);
	printf("Number: %d, power of %d\n", nb, power);
	printf("%d^%d: %d\n", nb, power, ft_iterative_power(nb, power));
	}
	else
	{
		printf("2 inputs required");
	}
	return (0);
}

