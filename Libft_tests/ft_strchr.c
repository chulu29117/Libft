/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:23:39 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:46:00 by clu              ###   ########.fr       */
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

// Test for ft_strchr /////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

void test_ft_strchr1()
{
    // Test case 1: Character is present in the string
    const char *str = "Hello, World!";
    char ch = 'W';
    char *result_ft = ft_strchr(str, ch);
    char *result_std = strchr(str, ch);
    printf("Test case 1:\nresult_ft = %s\nresult_std = %s\n", result_ft, result_std);
    printf("Match: %s\n\n", (result_ft == result_std) ? "Yes" : "No");
}

void test_ft_strchr2()
{
    // Test case 2: Character is not present in the string
    const char *str = "Hello, World!";
    char ch = 'x';
    char *result_ft = ft_strchr(str, ch);
    char *result_std = strchr(str, ch);
    printf("Test case 2:\nresult_ft = %s\nresult_std = %s\n", result_ft, result_std);
    printf("Match: %s\n\n", (result_ft == result_std) ? "Yes" : "No");
}

void test_ft_strchr3()
{
    // Test case 3: Character is the null terminator
    const char *str = "Hello, World!";
    char ch = '\0';
    char *result_ft = ft_strchr(str, ch);
    char *result_std = strchr(str, ch);
    printf("Test case 3:\nresult_ft = %s\nresult_std = %s\n", result_ft, result_std);
    printf("Match: %s\n\n", (result_ft == result_std) ? "Yes" : "No");
}

void test_ft_strchr4()
{
    // Test case 4: Empty string
    const char *str = "";
    char ch = 'H';
    char *result_ft = ft_strchr(str, ch);
    char *result_std = strchr(str, ch);
    printf("Test case 4:\nresult_ft = %s\nresult_std = %s\n", result_ft, result_std);
    printf("Match: %s\n\n", (result_ft == result_std) ? "Yes" : "No");
}

int main(void)
{
    test_ft_strchr1();
    test_ft_strchr2();
    test_ft_strchr3();
    test_ft_strchr4();
    return (0);
}
