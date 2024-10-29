/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:47:49 by clu               #+#    #+#             */
/*   Updated: 2024/09/10 09:24:43 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((src[i] != '\0') && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	main(void)
{
	char	src[] = "Hello";
	char	dest[30] = "World1";
	int	n;

	n = 4;
	printf("Str original: %s, %s\n", "Hello", "World1");
	ft_strncpy(dest, src, n);
	printf("Str copied with limited to length n (dest): %s, %s\n", src, dest);
	return (0);
}
