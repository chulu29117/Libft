/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:16:20 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 14:28:16 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function prototypes //
void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	// If either nmemb or size is 0, return a pointer to 0 bytes
	if (nmemb == 0 || size == 0)
		return (NULL);
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

#include <stdio.h>
// Test for ft_calloc



// Helper function //
void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
		ptr[i++] = 0;
}