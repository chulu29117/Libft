/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:50:03 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 11:53:32 by clu              ###   ########.fr       */
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
	return 0;
}
