/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:14:31 by clu               #+#    #+#             */
/*   Updated: 2024/09/10 18:14:33 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
				return(&str[i]);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	str[] = "Beam me up, Scotty!";
	char	to_find[] = "up";
	
	printf("String: %s\n To_find: %s\n", str, to_find);
	printf("To find in the string: %s\n", ft_strstr(str, to_find));
	return (0);
}
