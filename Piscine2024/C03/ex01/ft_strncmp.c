/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:51:24 by clu               #+#    #+#             */
/*   Updated: 2024/09/10 15:51:32 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	
	i = 0;
	
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] != '\0'))
	{
		if (i < (n -1))
			i++;
		else
			return (0);
	}
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char	s1[] = "HelloWorld";
	char	s2[] = "HelUIhuge";

	printf("Comparing strings s1 vs s2: %d\n", ft_strncmp(s1, s2, 3));
	return (0);
}
