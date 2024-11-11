/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:50:03 by clu               #+#    #+#             */
/*   Updated: 2024/11/04 20:09:26 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

#include <stdio.h>
// Test for ft_toupper
int	main(void)
{
	printf("ft_toupper('q') = %c\n", ft_toupper('q'));
	printf("ft_toupper('7') = %c\n", ft_toupper('7'));
	printf("ft_toupper('y') = %c\n", ft_toupper('y'));
	printf("ft_toupper('@') = %c\n", ft_toupper('@'));
	return (0);
}

// Built-in toupper
// #include <ctype.h>
// int	main(void)
// {
// 	printf("toupper('q') = %c\n", toupper('q'));
// 	printf("toupper('7') = %c\n", toupper('7'));
// 	printf("toupper('y') = %c\n", toupper('y'));
// 	printf("toupper('@') = %c\n", toupper('@'));
// 	return (0);
// }
