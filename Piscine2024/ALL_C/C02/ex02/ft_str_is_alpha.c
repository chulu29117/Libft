/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:03:07 by clu               #+#    #+#             */
/*   Updated: 2024/09/09 18:03:09 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z')))
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("Hello: %d\n", ft_str_is_alpha("Hello"));
	printf("!!@#$#: %d\n", ft_str_is_alpha("!!@#$#"));
	printf("123456: %d\n", ft_str_is_alpha("123456"));
	printf("Empty string: %d\n", ft_str_is_alpha(""));
	return (0);
}

