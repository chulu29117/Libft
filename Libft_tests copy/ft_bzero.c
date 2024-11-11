/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:54:17 by clu               #+#    #+#             */
/*   Updated: 2024/11/11 16:50:44 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
		ptr[i++] = 0;
}

// Test for ft_bzero

// Built-in bzero
// #include <strings.h>
// int	main(void)
// {
// 	char buffer1[10];
// 	char buffer2[10];
// 	size_t i;

// 	// Test case 1: Zero the entire buffer
// 	i = 0;
// 	while (i < 10) 
// 		buffer1[i++] = 'A';
// 	bzero(buffer1, 10);
// 	i = 0;
// 	while (i < 10) 
// 		printf("%d ", buffer1[i++]); // Output: 0 0 0 0 0 0 0 0 0 0
// 	printf("\n");

// 	// Test case 2: Zero the first half of the buffer
// 	i = 0;
// 	while (i < 10) 
// 		buffer2[i++] = 'A';
// 	bzero(buffer2, 5);
// 	i = 0;
// 	while (i < 10) 
// 		printf("%d ", buffer2[i++]); // Output: 0 0 0 0 0 65 65 65 65 65
// 	printf("\n");
// 	return (0);
// }
