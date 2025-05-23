/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:26:57 by clu               #+#    #+#             */
/*   Updated: 2024/11/13 15:37:14 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prototype functions //
size_t	ft_strlen(const char *str);

// Applies the function f to each character of the string passed as argument
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	if (!s || !f)
		return (NULL);
	new = (char *)malloc(ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	i = 0;
	// Loop through the string and apply the function f to each char in the string
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

// Test for ft_strmapi
#include <stdio.h>

char	ft_strmapi_test(unsigned int i, char c)
{
	return (c + 1 - i);	// Return the ASCII value of the char + i
}

int	main(void)
{
	char	*str = "`bdfh";
	char	*new;

	new = ft_strmapi(str, ft_strmapi_test);
	printf("Original: %s\n", str);
	printf("New: %s\n", new);
	free(new);
	return (0);
}

/// Helper function ft_strlen ///
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}