/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:04:44 by clu               #+#    #+#             */
/*   Updated: 2024/09/09 18:04:47 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("Hello: %d\n", ft_str_is_numeric("Hello"));
	printf("Hello123: %d\n", ft_str_is_numeric("Hello123"));
	printf("123456: %d\n", ft_str_is_numeric("12346"));
	printf("Empty string: %d\n", ft_str_is_numeric(""));
	return (0);
}
