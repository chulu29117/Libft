/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:23:05 by clu               #+#    #+#             */
/*   Updated: 2024/09/16 10:27:34 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_find_next_prime(int nb)
{
	int	i;
	
	if (nb <= 1)
		return (2);
	while (1)
	{
		i = 2;
		while (i * i <= nb)
		{
			if (nb % i == 0)
				break;
			i++;
		}
		if (i * i > nb)
			return (nb);
		nb++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
	int	nb = atoi(argv[1]);
	printf("Next prime after %d: %d\n", nb, ft_find_next_prime(nb));
	}
	else
	{
		printf("Input required");
	}
	return (0);
}	
