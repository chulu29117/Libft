/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:37:32 by clu               #+#    #+#             */
/*   Updated: 2024/09/13 19:37:34 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
	int	index = atoi(argv[1]);
	printf("Number: %d\n", index);
	printf("Fibonacci: %d\n", ft_fibonacci(index));
	}
	else
	{
		printf("Input required");
	}
	return (0);
}
