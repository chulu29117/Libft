/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:01:51 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 09:52:16 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function prototypes //
int	ft_isalpha(int c);
int	ft_isdigit(int c);

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
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
	return (0);
}

// Built-in isalnum
// #include <ctype.h>
// int	main(void)
// {
// 	printf("isalnum('Q') = %d\n", isalnum('Q'));
// 	printf("isalnum('7') = %d\n", isalnum('7'));
// 	printf("isalnum(' ') = %d\n", isalnum(' '));
// 	printf("isalnum('@') = %d\n", isalnum('@'));
// 	return (0);
// }

// Helper functions for ft_isalnum //
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}