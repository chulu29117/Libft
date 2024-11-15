/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:01:59 by clu               #+#    #+#             */
/*   Updated: 2024/11/13 15:07:59 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// Prototype functions //
size_t	ft_strlen(const char *str);

// Concatenate string src to the end of dest by size. 
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)	// If size is less than or equal to dest_len, return (src_len + size)
		return (src_len + size);
	i = 0;
	while (src[i] && dest_len + i < size - 1)	// Copy src to dest until the end of src or size - 1
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

#include <stdio.h>
// // Test for ft_strlcat
int	main(void)
{
	char	dest[] = "Hello";
	char	src[] = "Good";

	printf("src: %s dest: %s\n", src, dest);
	printf("Dest with size n: %ld\n", ft_strlcat(dest , src, 10));
	printf("dest: %s\n", dest);
	return (0);
}

// Helper functions //
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}