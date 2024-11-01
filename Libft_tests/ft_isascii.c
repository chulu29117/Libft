/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:48:11 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 11:50:47 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

#include <stdio.h>
// Test for ft_isascii
int	main(void)
{
	printf("ft_isascii('Q') = %d\n", ft_isascii('Q'));
	printf("ft_isascii('7') = %d\n", ft_isascii('7'));
	printf("ft_isascii(-123) = %d\n", ft_isascii(-123));
	printf("ft_isascii(402) = %d\n", ft_isascii(402));
	return (0);
}
