/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:02:26 by clu               #+#    #+#             */
/*   Updated: 2024/09/15 17:02:44 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	i;
	
	i = 0;
	if (nb == 0 || nb == 1)
		return (nb);
	while (i * i != nb && i < nb)
	{
		i++;
		if (i * i == nb)
			return (i);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
	int	nb = atoi(argv[1]);
	printf("Sqrt of %d: %d\n", nb, ft_sqrt(nb));
	}
	else
	{
		printf("Input required");
	}
	return (0);
}	
