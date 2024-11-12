/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:12:22 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:58:02 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_memset fills the first n bytes of the memory area pointed to by s with c.
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) s;	// Cast s to an unsigned char pointer
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;	// Set each byte to c
		i++;
	}
	return (s);
}

// Test for ft_memset /////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

void test_ft_memset1()
{
    // Test case 1: Setting the first 5 bytes to '*'
    char str1_ft[50] = "Hello, World!";
    char str1_std[50] = "Hello, World!";
	
    ft_memset(str1_ft, '*', 5);
    memset(str1_std, '*', 5);
    printf("Test case 1:\nstr1_ft = %s\nstr1_std = %s\n", str1_ft, str1_std);
    printf("Match: %s\n\n", (strcmp(str1_ft, str1_std) == 0) ? "Yes" : "No");
}

void test_ft_memset2()
{
    // Test case 2: Setting the entire string to 'A'
    char str2_ft[50] = "Hello, World!";
    char str2_std[50] = "Hello, World!";
	
    ft_memset(str2_ft, 'A', strlen(str2_ft));
    memset(str2_std, 'A', strlen(str2_std));
    printf("Test case 2:\nstr2_ft = %s\nstr2_std = %s\n", str2_ft, str2_std);
    printf("Match: %s\n\n", (strcmp(str2_ft, str2_std) == 0) ? "Yes" : "No");
}

void test_ft_memset3()
{
    // Test case 3: Setting 0 bytes (should not change the string)
    char str3_ft[50] = "Hello, World!";
    char str3_std[50] = "Hello, World!";
	
    ft_memset(str3_ft, '*', 2);
    memset(str3_std, '*', 2);
    printf("Test case 3:\nstr3_ft = %s\nstr3_std = %s\n", str3_ft, str3_std);
    printf("Match: %s\n\n", (strcmp(str3_ft, str3_std) == 0) ? "Yes" : "No");
}

int main(void)
{
    test_ft_memset1();
    test_ft_memset2();
    test_ft_memset3();
    return (0);
}
/////////////////////////////////////////////////////////////////////////////
