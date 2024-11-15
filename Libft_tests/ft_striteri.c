/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:23:47 by clu               #+#    #+#             */
/*   Updated: 2024/11/13 15:40:40 by clu              ###   ########.fr       */
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

// Test for ft_striteri /////////////////////////////////////////////////
#include <stdio.h>

void	ft_striteri_to_upper(unsigned int i, char *c)
{
    (void)i;
	if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

// Test case 1: Normal string
void test_ft_striteri1()
{
	char str[] = "ABCDEF";
	ft_striteri(str, &ft_striteri_to_upper);
	printf("Test case 1:\nOriginal: ABCDEF\nModified: %s\n\n", str);
}

// Test case 2: Empty string
void test_ft_striteri2()
{
    char str[] = "";
    ft_striteri(str, &ft_striteri_to_upper);
    printf("Test case 2:\nOriginal: (empty string)\nModified: %s\n\n", str);
}

// Test case 3: String with special characters
void test_ft_striteri3()
{
    char str[] = "Hello World !";
    ft_striteri(str, &ft_striteri_to_upper);
    printf("Test case 3:\nOriginal: Hello World !\nModified: %s\n\n", str);
}

// Test case 4: NULL string
void test_ft_striteri4()
{
    char *str = NULL;
    ft_striteri(str, &ft_striteri_to_upper);
    printf("Test case 4:\nOriginal: (NULL string)\nModified: (NULL string)\n\n");
}

int		main(void)
{
	test_ft_striteri1();
	test_ft_striteri2();
	test_ft_striteri3();
	test_ft_striteri4();
	return (0);
}
/////////////////////////////////////////////////////////////////////////////
