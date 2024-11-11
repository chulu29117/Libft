/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:16:20 by clu               #+#    #+#             */
/*   Updated: 2024/11/11 16:51:21 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	// If either nmemb or size is 0, return a pointer to 0 bytes
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	// If nmemb * size would overflow, return NULL
	if (nmemb && size > ((size_t)-1) / nmemb)
		return (NULL);
	// Allocate memory for nmemb * size bytes
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	// Zero the allocated memory
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// Test for ft_calloc

// Built-in calloc
// #include <stdlib.h>
// int	main(void)
// {
// 	int		*ptr;
// 	int		i;
// 	int		n;

// 	n = 5;
// 	ptr = (int *)calloc(n, sizeof(int));
// 	i = 0;
// 	while (i < n)
// 		printf("%d\n", ptr[i++]);
// 	return (0);
// }
