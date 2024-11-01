/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:08:36 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 11:50:26 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

#include <stdio.h>
// Test for ft_isalpha
int	main(void)
{
	printf("ft_isalpha('Q') = %d\n", ft_isalpha('Q'));
	printf("ft_isalpha('7') = %d\n", ft_isalpha('7'));
	printf("ft_isalpha('Y') = %d\n", ft_isalpha('Y'));
	printf("ft_isalpha('@') = %d\n", ft_isalpha('@'));
	return 0;
}
