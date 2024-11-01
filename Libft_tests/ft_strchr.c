/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:23:39 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 11:52:13 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *) & s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *) & s[i]);
	return (0);
}

#include <stdio.h>
// Test for ft_strchr
int	main(void)
{
	char *string = "Hello, World!";
	char *result;

	result = ft_strchr(string, 'o');
	printf("String after |%c| is - |%s|\n", 'o', result);
	return (0);
}
