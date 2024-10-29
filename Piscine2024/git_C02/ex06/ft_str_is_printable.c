/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:06:01 by clu               #+#    #+#             */
/*   Updated: 2024/09/09 18:06:03 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 127))
			return (0);
		i++;
	}
	return (1);
}

/*int	main(void)
{
	printf("Hello: %d\n", ft_str_is_printable("Hello"));
	printf("123456: %d\n", ft_str_is_printable("123456"));
	printf("€ÀÇœÕ: %d\n", ft_str_is_printable("€ÀÇœÕ"));
	printf("Empty string: %d\n", ft_str_is_printable(""));
	return (0);
}
*/
