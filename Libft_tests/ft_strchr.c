/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:23:39 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 10:21:46 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strchr() function locates the first occurrence of c (converted to a char) in the string 
char	*ft_strchr(const char *s, int c)
{
	int	i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			return ((char *) & s[i]);
		i++;
	}
	if (uc == '\0')
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

// Built in strchr
// #include <string.h>

// int	main(void)
// {
// 	char *string = "Hello, World!";
// 	char *result;

// 	result = strchr(string, 'o');
// 	printf("String after |%c| is - |%s|\n", 'o', result);
// 	return (0);
// }
