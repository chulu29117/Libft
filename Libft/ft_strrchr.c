/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:16:34 by clu               #+#    #+#             */
/*   Updated: 2024/11/04 15:56:26 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*last_occurrence;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	last_occurrence = 0;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			last_occurrence = (char *) & s[i];
		i++;
	}
	if (s[i] == uc)
		last_occurrence = (char *) & s[i];
	return (last_occurrence);
}
