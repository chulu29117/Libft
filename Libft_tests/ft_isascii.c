/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:48:11 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:58:42 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// Test for ft_isascii /////////////////////////////////////////////////
#include <stdio.h>

int	main(void)
{
	printf("ft_isascii('Q') = %d\n", ft_isascii('Q'));
	printf("ft_isascii('7') = %d\n", ft_isascii('7'));
	printf("ft_isascii(-123) = %d\n", ft_isascii(-123));
	printf("ft_isascii(402) = %d\n", ft_isascii(402));
	return (0);
}

// Built-in isascii
// #include <ctype.h>
// int	main(void)
// {
// 	printf("isascii('Q') = %d\n", isascii('Q'));
// 	printf("isascii('7') = %d\n", isascii('7'));
// 	printf("isascii(-123) = %d\n", isascii(-123));
// 	printf("isascii(402) = %d\n", isascii(402));
// 	return (0);
// }
/////////////////////////////////////////////////////////////////////////////
