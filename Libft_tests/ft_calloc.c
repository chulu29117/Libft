/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:16:20 by clu               #+#    #+#             */
/*   Updated: 2024/11/04 16:42:55 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
		ptr[i++] = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

#include <stdio.h>
// Test for ft_calloc
int	main(void)
{
	int		*ptr;
	int		i;
	int		n;

	n = 5;
	ptr = (int *)ft_calloc(n, sizeof(int));
	i = 0;
	while (i < n)
		printf("%d\n", ptr[i++]);
	return (0);
}

// Built-in calloc
// #include <stdlib.h>
// int	main(void)
// {
// 	int		*ptr;
// 	int		i;
// 	int		n;

// 	n = 5;
// 	ptr = (int *)calloc(n, sizeof(int));
// 	i = 0;
// 	while (i < n)
// 		printf("%d\n", ptr[i++]);
// 	return (0);
// }
