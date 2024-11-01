/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:40:01 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 12:08:34 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*ptr_dest;
	const char		*temp;

	ptr_dest = (char *)dest;
	temp = (const char *)src;
	if (ptr_dest > temp)
	{
		while (n--)
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
