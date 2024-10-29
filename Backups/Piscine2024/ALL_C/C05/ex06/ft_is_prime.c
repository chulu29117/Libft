/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:07:51 by clu               #+#    #+#             */
/*   Updated: 2024/09/15 18:07:53 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb)
{
	int i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i * i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
		

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
	int	nb = atoi(argv[1]);
	printf("Is %d a prime number? %d \n", nb, ft_is_prime(nb));
	}
	else
	{
		printf("Input required");
	}
	return (0);
}	
