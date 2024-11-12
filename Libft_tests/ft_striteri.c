/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:23:47 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 10:30:05 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_striteri applies the function f to each character of the string 
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f) 		// If s and f are not NULL
	{
		while (s[i])
		{
			f(i, &s[i]);	// Apply the function f to the character at index i
			i++;
		}
	}
}

// Test for ft_striteri
#include <stdio.h>

void	ft_striteri_test(unsigned int i, char *c)
{
	*c = (*c + i) % 128;	// Add i to the ASCII value of the char
}

int		main(void)
{
	char str[] = "ABCDEF";
	ft_striteri(str, &ft_striteri_test);
	printf("Original: ABCDEF\n");
	printf("Modified: %s\n", str);
	return (0);
}
