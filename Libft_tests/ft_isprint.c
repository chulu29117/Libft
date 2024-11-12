/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:06:01 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:44:09 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// Test for ft_isprint /////////////////////////////////////////////////
#include <stdio.h>

int	main(void)
{
	printf("ft_isprint('Q') = %d\n", ft_isprint('Q'));
	printf("ft_isprint('7') = %d\n", ft_isprint('7'));
	printf("ft_isprint(' ') = %d\n", ft_isprint(' '));
	printf("ft_isprint(128) = %d\n", ft_isprint(128));
	return (0);
}

// Built-in isprint
// #include <ctype.h>
// int	main(void)
// {
// 	printf("isprint('Q') = %d\n", isprint('Q'));
// 	printf("isprint('7') = %d\n", isprint('7'));
// 	printf("isprint(' ') = %d\n", isprint(' '));
// 	printf("isprint(128) = %d\n", isprint(128));
// 	return (0);
// }
