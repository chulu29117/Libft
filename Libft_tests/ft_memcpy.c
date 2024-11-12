/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:14 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:58:13 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_memcpy copies n bytes from src to dest.
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

// Test for ft_memcpy /////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

void test_ft_memcpy1()
{
    // Test case 1: Copying a string with n bytes
    char src1[] = "Hello, World!";
    char dest1_ft[50] = "";
    char dest1_std[50] = "";
    size_t n1 = 5;

    ft_memcpy(dest1_ft, src1, n1);
    memcpy(dest1_std, src1, n1);
    printf("Test case 1:\ndest1_ft = %s\ndest1_std = %s\n", dest1_ft, dest1_std);
	printf("Match: %s\n\n", (strcmp(dest1_ft, dest1_std) == 0) ? "Yes" : "No");
}
void test_ft_memcpy2()
{
    // Test case 2: Copying a string with n bytes, where n is larger than the source string length
    char src2[] = "Hello";
    char dest2_ft[50] = "";
    char dest2_std[50] = "";
    size_t n2 = strlen(src2) + 1; // Ensure n2 is not larger than the source string length

    ft_memcpy(dest2_ft, src2, n2);
    memcpy(dest2_std, src2, n2);
    printf("Test case 2:\ndest2_ft = %s\ndest2_std = %s\n", dest2_ft, dest2_std);
	printf("Match: %s\n\n", (strcmp(dest2_ft, dest2_std) == 0) ? "Yes" : "No");
}
void test_ft_memcpy3()
{	
    // Test case 3: Copying an empty string
    char src3[] = "";
    char dest3_ft[50] = "Good Morning!";
    char dest3_std[50] = "Good Morning!";
    size_t n3 = strlen(src3) + 1; // Ensure n3 is not larger than the source string length

    ft_memcpy(dest3_ft, src3, n3);
    memcpy(dest3_std, src3, n3);
 	printf("Test case 3:\ndest3_ft = %s\ndest3_std = %s\n", dest3_ft, dest3_std);
    printf("Match: %s\n\n", (strcmp(dest3_ft, dest3_std) == 0) ? "Yes" : "No");
}
void test_ft_memcpy4()
{
    // Test case 4: Copying a string with n = 0
    char src4[] = "Hello, World!";
    char dest4_ft[50] = "Good Morning!";
    char dest4_std[50] = "Good Morning!";
    size_t n4 = 0;

    ft_memcpy(dest4_ft, src4, n4);
    memcpy(dest4_std, src4, n4);
	printf("Test case 4:\ndest4_ft = %s\ndest4_std = %s\n", dest4_ft, dest4_std);
    printf("Match: %s\n\n", (strcmp(dest4_ft, dest4_std) == 0) ? "Yes" : "No");
}
int	main(void)
{
	test_ft_memcpy1();
	test_ft_memcpy2();
	test_ft_memcpy3();
	test_ft_memcpy4();
	return (0);
}
/////////////////////////////////////////////////////////////////////////////
