/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:28:21 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 10:33:51 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prototype functions //
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

// Allocates malloc and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));	// Allocate memory for res
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, ft_strlen(s1) + 1);						// Copy s1 to res
	ft_strlcat(res + ft_strlen(s1), s2, ft_strlen(s2) + 1);		// Concatenate s2 to the end of s1
	return (res);
}

#include <stdio.h>
// Test for ft_strjoin
int	main(void)
{
	char	*s1 = "Hello";
	char	*s2 = " World";
	char	*res;

	res = ft_strjoin(s1, s2);
	printf("s1: %s s2: %s\n", s1, s2);
	printf("Result: %s\n", res);
	free(res);
	return (0);
}

// Built-in strjoin
// #include <string.h>
// int	main(void)
// {
// 	char	*s1 = "Hello";
// 	char	*s2 = " World";
// 	char	*res;
//
// 	res = strdup(s1);
// 	strcat(res, s2);
// 	printf("s1: %s s2: %s\n", s1, s2);
// 	printf("Result: %s\n", res);
// 	free(res);
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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + size);
	i = 0;
	while (src[i] && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}