/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:40:01 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:45:01 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prototype functions //
void	*ft_memcpy(void *dest, const void *src, size_t n);

// ft_memmove copies n bytes from src to dest.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*ptr_dest;
	const char		*temp;

	ptr_dest = (char *)dest;
	temp = (const char *)src;
	if (ptr_dest > temp)	// If the destination is after the source.
	{
		while (n--)	// Copy from the end of the string to the beginning to avoid overwriting the source.
			ptr_dest[n] = temp[n];
	}
	else
		ft_memcpy(ptr_dest, temp, n);
	return (dest);
}

// Test for ft_memmove /////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

void test_ft_memmove1()
{
    // Test case 1: Moving a string with n bytes
    char src1[] = "Hello, World!";
    char dest1_ft[50] = "";
    char dest1_std[50] = "";
    size_t n1 = 5;

    ft_memmove(dest1_ft, src1, n1);
    memmove(dest1_std, src1, n1);
    printf("Test case 1:\ndest1_ft = %s\ndest1_std = %s\n", dest1_ft, dest1_std);
    printf("Match: %s\n\n", (strcmp(dest1_ft, dest1_std) == 0) ? "Yes" : "No");
}

void test_ft_memmove2()
{
    // Test case 2: Moving overlapping memory regions
    char src2[] = "Hello, World!";
    char dest2_ft[50] = "Hello, World!";
    char dest2_std[50] = "Hello, World!";
    size_t n2 = 5;

    ft_memmove(dest2_ft, src2, n2);
    memmove(dest2_std, src2, n2);
    printf("Test case 2:\ndest2_ft = %s\ndest2_std = %s\n", dest2_ft, dest2_std);
    printf("Match: %s\n\n", (strcmp(dest2_ft, dest2_std) == 0) ? "Yes" : "No");
}

void test_ft_memmove3()
{
    // Test case 3: Moving an empty string
    char src3[] = "";
    char dest3_ft[50] = "Good Morning!";
    char dest3_std[50] = "Good Morning!";
    size_t n3 = 1; // Ensure n3 is not larger than the source string length

    ft_memmove(dest3_ft, src3, n3);
    memmove(dest3_std, src3, n3);
    printf("Test case 3:\ndest3_ft = %s\ndest3_std = %s\n", dest3_ft, dest3_std);
    printf("Match: %s\n\n", (strcmp(dest3_ft, dest3_std) == 0) ? "Yes" : "No");
}

void test_ft_memmove4()
{
    // Test case 4: Moving a string with n = 0
    char src4[] = "Hello, World!";
    char dest4_ft[50] = "Good Morning!";
    char dest4_std[50] = "Good Morning!";
    size_t n4 = 0;

    ft_memmove(dest4_ft, src4, n4);
    memmove(dest4_std, src4, n4);
    printf("Test case 4:\ndest4_ft = %s\ndest4_std = %s\n", dest4_ft, dest4_std);
    printf("Match: %s\n\n", (strcmp(dest4_ft, dest4_std) == 0) ? "Yes" : "No");
}

int main(void)
{
    test_ft_memmove1();
    test_ft_memmove2();
    test_ft_memmove3();
    test_ft_memmove4();
    return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dest;
	char		*ptr_src;

	if (!dest && !src && n > 0)
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