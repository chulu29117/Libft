/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:12:22 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 11:52:03 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, t_size_t n)
{
	unsigned char	*ptr;
	t_size_t		i;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

#include <stdio.h>
// Test for ft_memset
int	main(void)
{
	char	str[50] = "Hello, World!";
	ft_memset(str, '*', 5);
	printf("After memset: %s\n", str);
	return (0);
}
