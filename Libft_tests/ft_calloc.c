/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:16:20 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 14:35:56 by clu              ###   ########.fr       */
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

// Test for ft_calloc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to compare ft_calloc and calloc
void compare_calloc(size_t count, size_t size)
{
    void *result_ft_calloc = ft_calloc(count, size);
    void *result_calloc = calloc(count, size);

    printf("Count: %zu, Size: %zu\n", count, size);
    printf("ft_calloc: ");
    size_t i = 0;
	// Print the memory addresses of the allocated memory with ft_calloc
    while (i < count * size)
    {
        printf("%d ", ((unsigned char *)result_ft_calloc)[i]);
        i++;
    }
    printf("\n");

    printf("calloc:    ");
    i = 0;
	// Print the memory addresses of the allocated memory with calloc
    while (i < count * size)
    {
        printf("%d ", ((unsigned char *)result_calloc)[i]);
        i++;
    }
    printf("\n");

    printf("Match: %s\n\n", (memcmp(result_ft_calloc, result_calloc, count * size) == 0) ? "Yes" : "No");

    free(result_ft_calloc);
    free(result_calloc);
}

// Test function for ft_calloc
void test_ft_calloc(void)
{
	compare_calloc(5, sizeof(int));
	compare_calloc(10, sizeof(char));
	compare_calloc(0, sizeof(int));
	compare_calloc(5, 0);
	compare_calloc(0, 0);
	compare_calloc(1, 100);
	compare_calloc(100, 1);
}

int main(void)
{
	test_ft_calloc();
	return 0;
}

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