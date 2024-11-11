/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:37:22 by clu               #+#    #+#             */
/*   Updated: 2024/11/11 15:51:32 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

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

// Test for ft_atoi
#include <stdio.h>

int	main(void)
{
	char	*str1 = "2532452452345345";
	char	*str2 = "-2532452452345345";
	char	*str3 = "2147483647"; // INT_MAX
	char	*str4 = "-2147483648"; // INT_MIN
	char	*str5 = "42";
	char	*str6 = "   -42";
	char	*str7 = "4193 with words";
	char	*str8 = "words and 987";
	char	*str9 = "-91283472332";
	char	*str10 = "91283472332";
	int		result;

	result = ft_atoi(str1);
	printf("Result for \"%s\": %d\n", str1, result);
	result = ft_atoi(str2);
	printf("Result for \"%s\": %d\n", str2, result);
	result = ft_atoi(str3);
	printf("Result for \"%s\": %d\n", str3, result);
	result = ft_atoi(str4);
	printf("Result for \"%s\": %d\n", str4, result);
	result = ft_atoi(str5);
	printf("Result for \"%s\": %d\n", str5, result);
	result = ft_atoi(str6);
	printf("Result for \"%s\": %d\n", str6, result);
	result = ft_atoi(str7);
	printf("Result for \"%s\": %d\n", str7, result);
	result = ft_atoi(str8);
	printf("Result for \"%s\": %d\n", str8, result);
	result = ft_atoi(str9);
	printf("Result for \"%s\": %d\n", str9, result);
	result = ft_atoi(str10);
	printf("Result for \"%s\": %d\n", str10, result);

	return (0);
}

// Built-in atoi
// int	main(void)
// {
// 	char	*str1 = "2532452452345345";
// 	char	*str2 = "-2532452452345345";
// 	char	*str3 = "2147483647"; // INT_MAX
// 	char	*str4 = "-2147483648"; // INT_MIN
// 	char	*str5 = "42";
// 	char	*str6 = "   -42";
// 	char	*str7 = "4193 with words";
// 	char	*str8 = "words and 987";
// 	char	*str9 = "-91283472332";
// 	char	*str10 = "91283472332";
// 	int		result;

// 	result = atoi(str1);
// 	printf("Result for \"%s\": %d\n", str1, result);
// 	result = atoi(str2);
// 	printf("Result for \"%s\": %d\n", str2, result);
// 	result = atoi(str3);
// 	printf("Result for \"%s\": %d\n", str3, result);
// 	result = atoi(str4);
// 	printf("Result for \"%s\": %d\n", str4, result);
// 	result = atoi(str5);
// 	printf("Result for \"%s\": %d\n", str5, result);
// 	result = atoi(str6);
// 	printf("Result for \"%s\": %d\n", str6, result);
// 	result = atoi(str7);
// 	printf("Result for \"%s\": %d\n", str7, result);
// 	result = atoi(str8);
// 	printf("Result for \"%s\": %d\n", str8, result);
// 	result = atoi(str9);
// 	printf("Result for \"%s\": %d\n", str9, result);
// 	result = atoi(str10);
// 	printf("Result for \"%s\": %d\n", str10, result);

// 	return (0);
// }
