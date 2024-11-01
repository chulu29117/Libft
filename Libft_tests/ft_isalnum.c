/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:01:51 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 11:50:07 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

#include <stdio.h>
// Test for ft_isalnum
int	main(void)
{
	printf("ft_isalnum('Q') = %d\n", ft_isalnum('Q'));
	printf("ft_isalnum('7') = %d\n", ft_isalnum('7'));
	printf("ft_isalnum(' ') = %d\n", ft_isalnum(' '));
	printf("ft_isalnum('@') = %d\n", ft_isalnum('@'));
	return 0;
}
