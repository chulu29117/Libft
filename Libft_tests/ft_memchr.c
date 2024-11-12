/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:53 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:58:22 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Search for the character c in the first n bytes of the string s
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		// If the character is found, return a pointer to the character
		if ((((unsigned char *)s)[i]) == ((unsigned char)c))
			return ((void *)s + i);
		i++;
	}
	return (0);
}

// Test for ft_memchr /////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

void test_memchr()
{
    char		*str1 = "Hello, World!";
    char		*result1_ft;
    char		*result1_std;
    int			c1 = 'W';
    size_t		n1 = 13;

    result1_ft = ft_memchr(str1, c1, n1);
    result1_std = memchr(str1, c1, n1);
    printf("ft_memchr: String after %c is - %s\n", c1, result1_ft);
    printf("memchr: String after %c is - %s\n", c1, result1_std);

    char		*str2 = "Another test string";
    char		*result2_ft;
    char		*result2_std;
    int			c2 = 't';
    size_t		n2 = 20;

    result2_ft = ft_memchr(str2, c2, n2);
    result2_std = memchr(str2, c2, n2);
    printf("ft_memchr: String after %c is - %s\n", c2, result2_ft);
    printf("memchr: String after %c is - %s\n", c2, result2_std);

    char		*str3 = "No match case";
    char		*result3_ft;
    char		*result3_std;
    int			c3 = 'z';
    size_t		n3 = 14;

    result3_ft = ft_memchr(str3, c3, n3);
    result3_std = memchr(str3, c3, n3);
    if (result3_ft)
        printf("ft_memchr: String after %c is - %s\n", c3, result3_ft);
    else
        printf("ft_memchr: Character %c not found\n", c3);
    if (result3_std)
        printf("memchr: String after %c is - %s\n", c3, result3_std);
    else
        printf("memchr: Character %c not found\n", c3);

    char		*str4 = "Edge case test";
    char		*result4_ft;
    char		*result4_std;
    int			c4 = 'E';
    size_t		n4 = 0;

    result4_ft = ft_memchr(str4, c4, n4);
    result4_std = memchr(str4, c4, n4);
    if (result4_ft)
        printf("ft_memchr: String after %c is - %s\n", c4, result4_ft);
    else
        printf("ft_memchr: Character %c not found\n", c4);
    if (result4_std)
        printf("memchr: String after %c is - %s\n", c4, result4_std);
    else
        printf("memchr: Character %c not found\n", c4);
}

int	main(void)
{
    test_memchr();
    return (0);
}
/////////////////////////////////////////////////////////////////////////////
