/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:53 by clu               #+#    #+#             */
/*   Updated: 2024/11/11 16:25:49 by clu              ###   ########.fr       */
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

#include <stdio.h>
// Test for ft_memchr
int	main(void)
{
	char		*str1 = "Hello, World!";
	char		*result1;
	int			c1 = 'W';
	size_t		n1 = 13;

	result1 = ft_memchr(str1, c1, n1);
	printf("String after %c is - %s\n", c1, result1);

	char		*str2 = "Another test string";
	char		*result2;
	int			c2 = 't';
	size_t		n2 = 20;

	result2 = ft_memchr(str2, c2, n2);
	printf("String after %c is - %s\n", c2, result2);

	char		*str3 = "No match case";
	char		*result3;
	int			c3 = 'z';
	size_t		n3 = 14;

	result3 = ft_memchr(str3, c3, n3);
	if (result3)
		printf("String after %c is - %s\n", c3, result3);
	else
		printf("Character %c not found\n", c3);

	char		*str4 = "Edge case test";
	char		*result4;
	int			c4 = 'E';
	size_t		n4 = 0;

	result4 = ft_memchr(str4, c4, n4);
	if (result4)
		printf("String after %c is - %s\n", c4, result4);
	else
		printf("Character %c not found\n", c4);

	return (0);
}

// Built-in memchr
// #include <string.h>
// int	main(void)
// {
// 	char		*str1 = "Hello, World!";
// 	char		*result1;
// 	int			c1 = 'W';
// 	size_t		n1 = 13;

// 	result1 = memchr(str1, c1, n1);
// 	printf("String after %c is - %s\n", c1, result1);

// 	char		*str2 = "Another test string";
// 	char		*result2;
// 	int			c2 = 't';
// 	size_t		n2 = 20;

// 	result2 = memchr(str2, c2, n2);
// 	printf("String after %c is - %s\n", c2, result2);

// 	char		*str3 = "No match case";
// 	char		*result3;
// 	int			c3 = 'z';
// 	size_t		n3 = 14;

// 	result3 = memchr(str3, c3, n3);
// 	if (result3)
// 		printf("String after %c is - %s\n", c3, result3);
// 	else
// 		printf("Character %c not found\n", c3);

// 	char		*str4 = "Edge case test";
// 	char		*result4;
// 	int			c4 = 'E';
// 	size_t		n4 = 0;

// 	result4 = memchr(str4, c4, n4);
// 	if (result4)
// 		printf("String after %c is - %s\n", c4, result4);
// 	else
// 		printf("Character %c not found\n", c4);

// 	return (0);
// }
