/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:01:59 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 11:52:21 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size_t	ft_strlcat(char *dest, const char *src, t_size_t size)
{
	t_size_t	dest_len;
	t_size_t	src_len;
	t_size_t	i;

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

#include <stdio.h>
// Test for ft_strlcat
int	main(void)
{
	char	dest[] = "Hello";
	char	src[] = "Good Morning World";

	printf("src: %s dest: %s\n", src, dest);
	printf("Dest with size n: %ld\n", ft_strlcat(dest, src, 3));
	printf("dest: %s\n", dest);
	return (0);
}
