/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:16:34 by clu               #+#    #+#             */
/*   Updated: 2024/11/28 13:28:19 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last_occurrence;
	unsigned char	uc;

	if (s == NULL)
		return (NULL);
	uc = (unsigned char)c;
	last_occurrence = NULL;
	while (*s)
	{
		if (*s == uc)
			last_occurrence = (char *)s;
		s++;
	}
	if (*s == uc)
		last_occurrence = (char *)s;
	return (last_occurrence);
}
