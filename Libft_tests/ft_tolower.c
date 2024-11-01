/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:53:41 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 11:53:25 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

#include <stdio.h>
// Test for ft_tolower
int	main(void)
{
	printf("ft_tolower('Q') = %c\n", ft_tolower('Q'));
	printf("ft_tolower('7') = %c\n", ft_tolower('7'));
	printf("ft_tolower('Y') = %c\n", ft_tolower('Y'));
	printf("ft_tolower('@') = %c\n", ft_tolower('@'));
	return 0;
}
