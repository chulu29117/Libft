/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:16:34 by clu               #+#    #+#             */
/*   Updated: 2024/10/30 14:36:29 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	char	*last_occurrence;

	i = 0;
	last_occurrence = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			last_occurrence = (char *) & s[i];
		i++;
	}
	if (s[i] == c)
		last_occurrence = (char *) & s[i];
	return last_occurrence;
}