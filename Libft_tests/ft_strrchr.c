/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:16:34 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 10:45:05 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a pointer to the last occurrence of the character c in the string s.
char	*ft_strrchr(const char *s, int c)
{
	char			*last_occurrence;
	unsigned char	uc;

	uc = (unsigned char)c;
	last_occurrence = NULL;
	while (*s)
	{
		if (*s == uc)
			last_occurrence = (char *)s;
		s++;
	}
	if (*s == uc)	// Check for the null terminator
		last_occurrence = (char *)s;
	return (last_occurrence);
}


#include <stdio.h>
// Test for ft_strrchr
int	main(void)
{
	char	*string = "Hello, World!";
	char	*result;

	result = ft_strrchr(string, 'o');
	printf("String after |%c| is - |%s|\n", 'o', result);
	return (0);
}

// Built-in strrchr
// #include <string.h>
// int	main(void)
// {
// 	char	*string = "Hello, World!";
// 	char	*result;

// 	result = strrchr(string, 'o');
// 	printf("String after |%c| is - |%s|\n", 'o', result);
// 	return (0);
// }
