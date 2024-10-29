/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:05:07 by clu               #+#    #+#             */
/*   Updated: 2024/09/09 18:05:09 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("Hello: %d\n", ft_str_is_lowercase("Hello"));
	printf("HeLLo: %d\n", ft_str_is_lowercase("HeLLo"));
	printf("hello: %d\n", ft_str_is_lowercase("hello"));
	printf("Empty string: %d\n", ft_str_is_lowercase(""));
	return (0);
}
