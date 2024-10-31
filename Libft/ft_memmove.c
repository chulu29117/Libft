/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:40:01 by clu               #+#    #+#             */
/*   Updated: 2024/10/31 12:17:54 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, t_size_t n)
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
