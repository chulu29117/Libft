/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testex01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:23:15 by clu               #+#    #+#             */
/*   Updated: 2024/09/08 15:24:40 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

int	main(void)
{
	int	i;
	int	*nbr1 = &i;
	int	**nbr2 = &nbr1;
	int	***nbr3 = &nbr2;
	int	****nbr4 = &nbr3;
	int	*****nbr5 = &nbr4;
	int	******nbr6 = &nbr5;
	int	*******nbr7 = &nbr6;
	int	********nbr8 = &nbr7;
	int	*********nbr9 = &nbr8;

	i = 10;
	
	printf("%d\n", i);
	ft_ultimate_ft(nbr9);
	printf("%d", i);
	return (0);
}
