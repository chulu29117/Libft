/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:55:40 by clu               #+#    #+#             */
/*   Updated: 2024/11/13 15:18:20 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compares strings s1 and s2 by n bytes

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

#include <stdio.h>
#include <string.h>
// Test for ft_strncmp
int	main(void)
{
	char		*str1 = "tests\200";
	char		*str2 = "tests\000";
	size_t		n = 6;

	printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, n));
	printf("strncmp: %d\n", strncmp(str1, str2, n));

	return (0);
}

// Built-in strncmp
// #include <string.h>
// int	main(void)
// {
// 	char		*str1 = "Hello, World!";
// 	char		*str2 = "Morning!";
// 	size_t		n = 5;

// 	printf("strncmp: %d\n", strncmp(str1, str2, n));
// 	return (0);
// }
