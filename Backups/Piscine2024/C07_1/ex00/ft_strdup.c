/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:32:49 by clu               #+#    #+#             */
/*   Updated: 2024/09/18 16:57:29 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
		str[i++];
	return (i)
}

char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	i;

	dest = (char *) malloc(strlen(src) + 1);
		
 
}
