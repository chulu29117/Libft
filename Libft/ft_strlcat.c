/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:01:59 by clu               #+#    #+#             */
/*   Updated: 2024/10/30 16:11:13 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size_t	ft_strlcat(char *dest, const char *src, t_size_t size)
{
	t_size_t	i;
	t_size_t	j;
	t_size_t	dest_len;
	t_size_t	src_len;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
			return (size + src_len);
	i = dest_len;
	j = 0;
	while ((src[j] != '\0') && (i <= size -1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i + size);
}