/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:48:22 by clu               #+#    #+#             */
/*   Updated: 2024/09/08 15:48:29 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void)
{
	int	a;
	int	b;
	a = 10;
	b = 20;
	
	printf("Before swap: a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("After swap: a = %d, b = %d\n", a, b);
	return (0);
}
