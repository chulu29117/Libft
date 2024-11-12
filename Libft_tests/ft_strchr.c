/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:23:39 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 14:00:55 by clu              ###   ########.fr       */
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

void test_functions(void)
{
	char *string = "Hello, World!";
	char *result;

	// Test case 1: Search for 'o' in the string
	result = ft_strchr(string, 'o');
	printf("Test case 1: String after |%c| is - |%s|\n", 'o', result);

	// Test case 2: Search for 'z' in the string
	result = ft_strchr(string, 'z');
	printf("Test case 2: String after |%c| is - |%s|\n", 'z', result);

	// Test case 3: Search for '\0' in the string
	result = ft_strchr(string, '\0');
	printf("Test case 3: String after |%c| is - |%s|\n", '\0', result);

	// Test case 4: Search for 'H' in the string
	result = ft_strchr(string, 'H');
	printf("Test case 4: String after |%c| is - |%s|\n", 'H', result);
}

int main(void)
{
	test_functions();
	return 0;
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
