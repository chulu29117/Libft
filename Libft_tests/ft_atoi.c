/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:37:22 by clu               #+#    #+#             */
/*   Updated: 2024/11/08 14:25:43 by clu              ###   ########.fr       */
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
		if ((res > (INT_MAX - (*str - '0')) / 10) && sign == 1)
			return (INT_MAX);
		else if ((res < (INT_MIN - (*str - '0')) / 10) && sign == -1)
			return (INT_MIN);
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)(res * sign));
}

// Test for ft_atoi
#include <stdio.h>

int	main(void)
{
	char	*str = "2532452452345345";
	int		result;

	result = ft_atoi(str);
	printf("Result: %d\n", result);
	return (0);
}

// Built-in atoi
// int	main(void)
// {
// 	char	*str = "-112355";
// 	int		result;

// 	result = ft_atoi(str);
// 	printf("Result: %d\n", result);
// 	return (0);
// }