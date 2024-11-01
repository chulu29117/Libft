/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:26:38 by clu               #+#    #+#             */
/*   Updated: 2024/11/01 11:50:58 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

#include <stdio.h>
// Test for ft_isdigit
int	main(void)
{
	printf("ft_isdigit('Q') = %d\n", ft_isdigit('Q'));
	printf("ft_isdigit('7') = %d\n", ft_isdigit('7'));
	printf("ft_isdigit('3') = %d\n", ft_isdigit('3'));
	printf("ft_isdigit('@') = %d\n", ft_isdigit('@'));
	return 0;
}
