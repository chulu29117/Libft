/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:19 by clu               #+#    #+#             */
/*   Updated: 2024/09/17 13:06:21 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*res;
	int	i;

	if (min >= max)
		return (NULL);
	range = max - min;
	res = (int *) malloc(sizeof(int) * range);
	i = 0;
	while (min < max)
		res[i++] = min++;
	return (res);
}

int	main(int argc, char *argv[])
{
	int	num;
	int	num2;
	int	*array;
	int	i;
	
	num = atoi(argv[1]);
	num2 = atoi(argv[2]);
	array = ft_range(num, num2);
	
	if (argc == 3)
	{
		i = 0;
		while (i < (num2 - num))
			printf("%d ", array[i++]);
	}
	else
		printf("2 Input required");
	return (0);
}		
