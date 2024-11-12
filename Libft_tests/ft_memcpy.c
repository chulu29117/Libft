/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:14 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 10:04:01 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_memcpy copies n bytes from src to dest.
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
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

#include <stdio.h>
// Test for ft_memcpy
int	main(void)
{
	char	src[30] = "Hello, World!";
	char	dest[30] = "Good Morning!";
	char	*result;

	result = ft_memcpy(dest, src, 5);
	printf("Result: %s\n", result);
	return (0);
}

// Built-in memcpy
// #include <string.h>
// int	main(void)
// {
// 	char	src[30] = "Hello, World!";
// 	char	dest[30] = "Good Morning!";
// 	char	*result;

// 	result = memcpy(dest, src, 5);
// 	printf("Result: %s\n", result);
// 	return (0);
// }
