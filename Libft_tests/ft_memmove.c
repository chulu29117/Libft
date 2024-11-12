/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:40:01 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 10:10:38 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prototype functions //
void	*ft_memcpy(void *dest, const void *src, size_t n);

// ft_memmove copies n bytes from src to dest.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*ptr_dest;
	const char		*temp;

	ptr_dest = (char *)dest;
	temp = (const char *)src;
	if (ptr_dest > temp)	// If the destination is after the source.
	{
		while (n--)	// Copy from the end of the string to the beginning to avoid overwriting the source.
			ptr_dest[n] = temp[n];
	}
	else
		ft_memcpy(ptr_dest, temp, n);
	return (dest);
}

#include <stdio.h>
// Test for ft_memmove
int	main(void)
{
	char src[] = "Hello, World!";
	char dest[] = "Good Morning!";

	printf("Before memmove, src: %s, dest: %s\n", src, dest);
	ft_memmove(dest, src, 14);
	printf("After memmove, src: %s, dest: %s\n", src, dest);
	return (0);
}

// Built-in memmove
// #include <string.h>
// int	main(void)
// {
// 	char src[] = "Hello, World!";
// 	char dest[] = "Good Morning!";
//
// 	printf("Before memmove, src: %s, dest: %s\n", src, dest);
// 	memmove(dest, src, 14);
// 	printf("After memmove, src: %s, dest: %s\n", src, dest);
// 	return (0);
// }

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