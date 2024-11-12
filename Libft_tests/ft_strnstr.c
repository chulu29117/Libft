/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:26:52 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 10:42:08 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates the first occurrence of little in the string big, where not more than len characters are searched.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (0);
}

#include <stdio.h>
// Test for ft_strnstr
int	main(void)
{
	char	*str = "Hello, World!";
	char	*to_find = "World";
	size_t	len = 13;

	printf("String: %s\n", str);
	printf("To find: %s\n", to_find);
	printf("Result: %s\n", ft_strnstr(str, to_find, len));
	return (0);
}
