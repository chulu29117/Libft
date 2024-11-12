/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:34:07 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:44:43 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memcmp() function compares string s1 against string s2.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

// Test for ft_memcmp /////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

void	test_memcmp()
{
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    char str3[] = "Hello, world!";
    char str4[] = "Hello, Wxrld!";
    size_t n = 13;

    int result1_ft = ft_memcmp(str1, str2, n);
    int result1_std = memcmp(str1, str2, n);
    printf("ft_memcmp(str1, str2, %zu) = %d, memcmp(str1, str2, %zu) = %d, Match: %s\n",
           n, result1_ft, n, result1_std, (result1_ft == result1_std) ? "Yes" : "No");

    int result2_ft = ft_memcmp(str1, str3, n);
    int result2_std = memcmp(str1, str3, n);
    printf("ft_memcmp(str1, str3, %zu) = %d, memcmp(str1, str3, %zu) = %d, Match: %s\n",
           n, result2_ft, n, result2_std, (result2_ft == result2_std) ? "Yes" : "No");

    int result3_ft = ft_memcmp(str1, str4, n);
    int result3_std = memcmp(str1, str4, n);
    printf("ft_memcmp(str1, str4, %zu) = %d, memcmp(str1, str4, %zu) = %d, Match: %s\n",
           n, result3_ft, n, result3_std, (result3_ft == result3_std) ? "Yes" : "No");

    int result4_ft = ft_memcmp(str3, str4, n);
    int result4_std = memcmp(str3, str4, n);
    printf("ft_memcmp(str3, str4, %zu) = %d, memcmp(str3, str4, %zu) = %d, Match: %s\n",
           n, result4_ft, n, result4_std, (result4_ft == result4_std) ? "Yes" : "No");
}

int	main(void)
{
    test_memcmp();
    return (0);
}
