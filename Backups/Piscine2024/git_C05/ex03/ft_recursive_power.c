/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:51:10 by clu               #+#    #+#             */
/*   Updated: 2024/09/13 18:51:13 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

/*int	main(int argc, char *argv[])
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
*/
