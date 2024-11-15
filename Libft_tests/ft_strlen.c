/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:48:09 by clu               #+#    #+#             */
/*   Updated: 2024/11/13 14:49:59 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the length of the string.
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

#include <stdio.h>
// Test for ft_strlen
int	main(void)
{
	int	strlen;
	
	strlen = ft_strlen("Hello");
	printf("Number of characters: %d\n", strlen);
	return (0);
}

// Built-in strlen
// #include <string.h>
// int	main(void)
// {
// 	int	len;

// 	len = strlen("Hello");
// 	printf("Number of characters: %d\n", len);
// 	return (0);
// }
