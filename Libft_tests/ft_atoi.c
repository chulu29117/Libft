/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:37:22 by clu               #+#    #+#             */
/*   Updated: 2024/11/13 22:28:26 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prototype //
int	ft_isdigit(int c);

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
		if (res > LONG_MAX && sign == 1)
			return (-1);
		if (res > LONG_MAX && sign == -1)
			return (0);
	} 
	return ((int)(res * sign));
}

// Test for ft_atoi /////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

// Helper function to compare ft_atoi and atoi
void compare_atoi(const char *str)
{
    int result_ft_atoi = ft_atoi(str);
    int result_atoi = atoi(str);

    printf("Input: \"%s\"\n", str);
    printf("ft_atoi: %d\n", result_ft_atoi);
    printf("atoi:    %d\n", result_atoi);
    printf("Match:   %s\n\n", (result_ft_atoi == result_atoi) ? "Yes" : "No");
}

// Test function for ft_atoi
void test_ft_atoi(void)
{
    compare_atoi("42");						// atoi returns 42
    compare_atoi("   -42");					// atoi returns -42
    compare_atoi("0");						// atoi returns 0
    compare_atoi("1234 with words");		// atoi returns 1234
    compare_atoi("words and 987");			// atoi returns 0
	printf("OVERFLOW TESTS\n---------------------\n");
	printf("\"int_max\"\n");
    compare_atoi("2147483647");				// int_max
	printf("\"int_min\"\n");
    compare_atoi("-2147483648");			// int_min
	printf("\"int_max + 1\"\n");
	compare_atoi("2147483648");				// int_max + 1
	printf("\"int_min - 1\"\n");
    compare_atoi("-2147483649");			// int_min - 1
	printf("\"long_max\"\n");	
    compare_atoi("9223372036854775807");	// long_max
	printf("\"long_min\"\n");
    compare_atoi("-9223372036854775808");	// long_min
	printf("\"long_max + 1\"\n");
	compare_atoi("9223372036854775808");	// long_max + 1
	printf("\"long_min - 1\"\n");
	compare_atoi("-9223372036854775809");	// long_min - 1
}

int main(void)
{
    test_ft_atoi();
    return 0;
}
/////////////////////////////////////////////////////////////////////////////

// Helper functions //
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}