/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:22:54 by clu               #+#    #+#             */
/*   Updated: 2024/09/17 16:22:55 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*res;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	res = (int *) malloc((max - min) * sizeof(int));
	if (res == NULL)
		return (-1);
	i = 0;
	while (min < max)
		res[i++] = min++;
	*range = res;
	return(i);
}

int	main(int argc, char *argv[])
{
	int	num;
	int	num2;
	int	*range;

	num = atoi(argv[1]);
	num2 = atoi(argv[2]);

	if (argc != 3)
	{
		printf("2 Inputs required\n");
		return (1);
	}
	else	
		printf("%d ", ft_ultimate_range(&range, num, num2));
	return (0);
}
