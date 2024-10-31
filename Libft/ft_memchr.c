/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:53 by clu               #+#    #+#             */
/*   Updated: 2024/10/31 14:30:49 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, t_size_t n)
{
	t_size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s)[i]) == ((unsigned char)c))
			return ((void *)s + i);
		i++;
	}
	return (0);
}
