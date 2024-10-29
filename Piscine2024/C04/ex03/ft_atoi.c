/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:40:23 by clu               #+#    #+#             */
/*   Updated: 2024/09/12 11:40:24 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;
	
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{ 
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	main(void)
{
	char	str[] = "  ---1234ab567";
	
	printf("String: %s\n", str);
	printf("String atoi: %d\n", ft_atoi(str));
	return (0);
}		
