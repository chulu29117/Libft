/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:00:47 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 10:26:53 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prototype functions //
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	size_t		len;

	len = ft_strlen(s1) + 1;	// +1 for the null-terminator
	ptr = (char *)malloc(len); 	// Allocate memory for the string
	if (ptr == NULL)			// If malloc fails, return 0
		return (NULL);
	ft_memcpy(ptr, s1, len);	// Copy the string to the allocated memory
	return (ptr);
}

// Test for ft_strdup
#include <stdio.h>

int	main(void)
{
	char	*str = "Hello, World!";
	char	*res;

	res = ft_strdup(str);
	printf("Original string: %s\n", str);
	printf("Duplicated string: %s\n", res);
	free(res);
	return (0);
}

// Built-in strdup
// #include <string.h>
// int	main(void)
// {
// 	char	*str = "Hello, World!";
// 	char	*res;
//
// 	res = strdup(str);
// 	printf("Original string: %s\n", str);
// 	printf("Duplicated string: %s\n", res);
// 	return (0);
// }

// Helper functions //
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dest;
	char		*ptr_src;

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