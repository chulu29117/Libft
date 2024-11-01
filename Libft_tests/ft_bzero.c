/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:54:17 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 11:49:06 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, t_size_t n)
{
	t_size_t	i;
	char		*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

#include <stdio.h>
// Test for ft_bzero
int	main(void) 
{
	char buffer[10];
	t_size_t i;
	// Fill buffer with non-zero values
	i = 0;
	while (i < 10) {
		buffer[i] = 'A';
		i++;
	}
	// Zero the buffer using ft_bzero
	ft_bzero(buffer, 10);
	i = 0;
	while (i < 10) {
		printf("%d ", buffer[i]); // Output: 0 0 0 0 0 0 0 0 0 0
		i++;
	}
	printf("\n");
	return (0);
}
