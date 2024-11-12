/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:26:38 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:43:57 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// Test for ft_isdigit /////////////////////////////////////////////////
#include <stdio.h>

int	main(void)
{
	printf("ft_isdigit('Q') = %d\n", ft_isdigit('Q'));
	printf("ft_isdigit('7') = %d\n", ft_isdigit('7'));
	printf("ft_isdigit('3') = %d\n", ft_isdigit('3'));
	printf("ft_isdigit('@') = %d\n", ft_isdigit('@'));
	return (0);
}

// Built-in isdigit
// #include <ctype.h>
// int	main(void)
// {
// 	printf("isdigit('Q') = %d\n", isdigit('Q'));
// 	printf("isdigit('7') = %d\n", isdigit('7'));
// 	printf("isdigit('3') = %d\n", isdigit('3'));
// 	printf("isdigit('@') = %d\n", isdigit('@'));
// 	return (0);
// }
