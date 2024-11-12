/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:37:22 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:59:41 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prototype //
int	ft_isdigit(int c);

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

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
		if (res > (INT_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (INT_MAX);
			return (INT_MIN);
		}
		res = res * 10 + (*str - '0');
		str++;
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
    compare_atoi("42");
    compare_atoi("   -42");
    compare_atoi("4193 with words");
    compare_atoi("words and 987");
    compare_atoi("-91283472332");
    compare_atoi("2147483647");
    compare_atoi("-2147483648");
    compare_atoi("2147483648");
    compare_atoi("-2147483649");
    compare_atoi("0");
    compare_atoi("   +0");
    compare_atoi("   +123");
    compare_atoi("   -123");
    compare_atoi("   123abc456");
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