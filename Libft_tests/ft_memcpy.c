/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:14 by clu               #+#    #+#             */
/*   Updated: 2024/11/15 16:50:50 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_memcpy() copies n bytes from memory area src to memory area dest.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*ptr_dest;
	const char		*ptr_src;

	if (!dest && !src)
		return (NULL);
	i = 0;
	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

// Test for ft_memcpy /////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_ft_memcpy(void)
{
	char src1[] = "Hello, World!";
	char dest1[50];
	char dest2[50];

	// Test 1: Basic functionality
	ft_memcpy(dest1, src1, strlen(src1) + 1);
	memcpy(dest2, src1, strlen(src1) + 1);
	printf("ft_memcpy: %s\n", dest1);
	printf("memcpy: %s\n", dest2);
	if (strcmp(dest1, dest2) == 0)
		printf("Test 1 passed\n");
	else
		printf("Test 1 failed\n");

	// Test 2: Copying zero bytes
	char src2[] = "Test";
	char dest3[50] = "Initial";
	char dest4[50] = "Initial";
	ft_memcpy(dest3, src2, 0);
	memcpy(dest4, src2, 0);
	printf("ft_memcpy: %s\n", dest3);
	printf("memcpy: %s\n", dest4);
	if (strcmp(dest3, dest4) == 0)
		printf("Test 2 passed\n");
	else
		printf("Test 2 failed\n");

	// Test 3: Overlapping memory areas
	char src3[] = "Overlap";
	ft_memcpy(src3 + 2, src3, 5);
	memcpy(src3 + 2, src3, 5);
	printf("ft_memcpy: %s\n", src3);
	printf("memcpy: %s\n", src3);
	if (strcmp(src3, "OvOverlap") == 0)
		printf("Test 3 passed\n");
	else
		printf("Test 3 failed\n");

	// Test 4: Null pointers
	if (ft_memcpy(NULL, NULL, 5) == NULL)
		printf("Test 4 passed\n");
	else
		printf("Test 4 failed\n");
}

int main(void)
{
	test_ft_memcpy();
	return 0;
}
