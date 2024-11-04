/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:53 by clu               #+#    #+#             */
/*   Updated: 2024/11/04 19:01:01 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
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
	char		*str = "Hello, World!";
	char		*result;
	int			c = 'W';
	size_t	n = 13;

	result = ft_memchr(str, c, n);
	printf("String after %c is - %s\n", c, result);
	return (0);
}

// Built-in memchr
// #include <string.h>
// int	main(void)
// {
// 	char		*str = "Hello, World!";
// 	char		*result;
// 	int			c = 'W';
// 	size_t	n = 13;
//
// 	result = memchr(str, c, n);
// 	printf("String after %c is - %s\n", c, result);
// 	return (0);
// }
